module type Configuration = {
  type route;
  let routes: list(route);
};

module Make = (Config: Configuration) => {
  module NavigationProp = {
    type t;
    
    [@bs.send] external push: string => unit = "push";
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

    let configure = (mapRoute: mapRoute, initial: Config.route) => {
      let routes =
        List.map(
          route => {
            let (name, rest) = mapRoute(route);

            (name, configureRouteToJs(rest));
          },
          Config.routes,
        )
        |> Js.Dict.fromList;

      let (initial, _) = mapRoute(initial);

      _createStackNavigator(routes, {"initialRouteName": initial});
    };
  };
};
