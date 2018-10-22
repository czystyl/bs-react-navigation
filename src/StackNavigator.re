[@bs.deriving jsConverter]
type routeConfiguration = {screen: ReasonReact.reactClass};

[@bs.deriving jsConverter]
type navigatorConfig = {initialRouteName: string};

module type Configuration = {
  type routes;
  let navigatorConfig: navigatorConfig;
  let routes: list(routes);
  let mapRoute: routes => (string, routeConfiguration);
};

module CreateStackNavigator = (Config: Configuration) => {
  module StackNavigator = {
    [@bs.module "react-navigation"]
    external _createSN:
      (
        Js.Dict.t({. "screen": ReasonReact.reactClass}),
        {. "initialRouteName": string}
      ) =>
      ReasonReact.reactElement =
      "createStackNavigator";

    let stackConfig =
      Config.routes
      |> List.map(route => {
           let (name, configuration) = Config.mapRoute(route);

           (name, routeConfigurationToJs(configuration));
         })
      |> Js.Dict.fromList;

    let sConfig = navigatorConfigToJs(Config.navigatorConfig);

    let navigator = _createSN(stackConfig, sConfig);
  };
};
