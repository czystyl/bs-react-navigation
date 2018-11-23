module type Configuration = {
  type route;
  let routes: list(route);
};

module Make = (Config: Configuration) => {
  module Navigator = {
    [@bs.deriving jsConverter]
    type navigationProp = {
      push: string => unit,
      goBack: unit => unit,
    };

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
              let nav = navigationPropFromJs(orgNav##navigation);

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
