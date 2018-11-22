module type Configuration = {
  type route;
  let routes: list(route);
};

module Make = (Config: Configuration) => {
  module NavigationProp = {
    type t = {. "push": string => unit};

    [@bs.send] external push: (t, string) => unit = "push";
  };

  module NavigationOptions = {
    type t = {. "navigation": NavigationProp.t};
  };

  module Navigator = {
    [@bs.deriving jsConverter]
    type configureRoute = {
      screen: NavigationOptions.t => ReasonReact.reactElement,
    };

    type mapRoute = Config.route => (string, configureRoute);

    [@bs.module "react-navigation"]
    external _createStackNavigator:
      (
        Js.Dict.t({
          .
          "screen": NavigationOptions.t => ReasonReact.reactElement,
        }),
        {. "initialRouteName": string}
      ) =>
      ReasonReact.reactElement =
      "createStackNavigator";

    /* Configure stack navigation component */
    let configure = (mapRoute: mapRoute, initial: Config.route) => {
      /* create RN-navigation config object */
      let routes =
        List.map(
          route => {
            let (name, rest) = mapRoute(route);

            (name, configureRouteToJs(rest));
          },
          Config.routes,
        )
        |> Js.Dict.fromList;

      /* tmp */
      let (initialRoute, _) = mapRoute(initial);

      _createStackNavigator(routes, {"initialRouteName": initialRoute});
    };
  };
};
