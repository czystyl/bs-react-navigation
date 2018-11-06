[@bs.deriving jsConverter]
type navigatorConfig('a) = {initialRouteName: 'a};

type configureRoute = {screen: string => ReasonReact.reactElement};

module type Configuration = {
  type routes;
  
  let navigatorConfig: navigatorConfig(routes);
  let routes: list(routes);
  let mapRoute: routes => (string, configureRoute);
};

module CreateStackNavigator = (Config: Configuration) => {
  module StackNavigator = {
    type navWithRoute = string => ReasonReact.reactElement;

    [@bs.deriving jsConverter]
    type routeConfiguration = {screen: string => ReasonReact.reactElement};

    /* Bindings to the createStackNavigator */
    [@bs.module "react-navigation"]
    external _createStackNavigator:
      (
        Js.Dict.t({. "screen": navWithRoute}),
        {. "initialRouteName": string}
      ) =>
      ReasonReact.reactElement =
      "createStackNavigator";

    /* List of routes transformed to the JS object with {key: value} */
    let routes =
      Config.routes
      |> List.map(route => {
           let (name, routeConfig) = Config.mapRoute(route);

           let screen = navigation => routeConfig.screen(navigation);

           (name, routeConfigurationToJs({screen: screen}));
         })
      |> Js.Dict.fromList;

    /* Initial configuration */
    let (initialRouteName, _) =
      Config.mapRoute(Config.navigatorConfig.initialRouteName);

    /* React class navigator */
    let navigator =
      _createStackNavigator(
        routes,
        navigatorConfigToJs({initialRouteName: initialRouteName}),
      );
  };
};
