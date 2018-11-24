module type Configuration = {
  type route;
  let routes: list(route);
};

module Make = (Config: Configuration) => {
  module Navigator = {
    [@bs.deriving jsConverter]
    type state = {key: string};

    type stateJ = {. "key": string};

    [@bs.deriving jsConverter]
    type navigationProp = {
      push: Config.route => unit,
      goBack: unit => unit,
      state,
    };

    type navprop = {
      .
      "push": Config.route => unit,
      "goBack": unit => unit,
      "state": stateJ,
    };

    [@bs.send] external _push: (navprop, string, 'a) => unit = "push";
    [@bs.send] external _goBack: (navprop, unit) => unit = "goBack";

    [@bs.deriving jsConverter]
    type configureRoute = {
      screen: navigationProp => ReasonReact.reactElement,
    };

    [@bs.module "react-navigation"]
    external _createStackNavigator: ('a, 'b) => ReasonReact.reactElement =
      "createStackNavigator";

    [@bs.module "react-navigation"]
    external _createAppContainer: 'a => ReasonReact.reactElement =
      "createAppContainer";

    type mapRoute = Config.route => (string, configureRoute);

    let configure = (mapRoute: mapRoute, initial: Config.route) => {
      let routes =
        List.map(
          route => {
            let (name, config) = mapRoute(route);

            let makeNavigationProp = orgNav => {
              let bindPush = r => {
                let (name, _) = mapRoute(r);
                _push(orgNav##navigation, name, [%bs.raw {| r[0] |}]);
              };

              let nav = {
                push: bindPush,
                goBack: _goBack(orgNav##navigation),
                state: stateFromJs(orgNav##navigation##state),
              };

              config.screen(nav);
            };

            let optioin = {"screen": makeNavigationProp};
            (name, optioin);
          },
          Config.routes,
        )
        |> Js.Dict.fromList;

      let (initialRoute, _) = mapRoute(initial);

      _createAppContainer(
        _createStackNavigator(routes, {"initialRouteName": initialRoute}),
      );
    };
  };
};
