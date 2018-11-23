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
    external _createStackNavigator:
      (
        Js.Dict.t({
          .
          "screen":
            Js.t({.. navigation: {.. "push": string => unit}} as 'a) =>
            ReasonReact.reactElement,
        }),
        {. "initialRouteName": string}
      ) =>
      ReasonReact.reactElement =
      "createStackNavigator";

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

      _createStackNavigator(routes, {"initialRouteName": initialRoute});
    };
  };
};
