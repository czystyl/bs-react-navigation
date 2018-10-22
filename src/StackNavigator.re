[@bs.deriving jsConverter]
type routeConfiguration = {screen: ReasonReact.reactClass};

module type Configuration = {
  type routes;
  type routeConfig;
  let routes: list(routes);
  let mapRoute: routes => (string, routeConfiguration);
};

module CreateStackNavigator = (Config: Configuration) => {
  module StackNavigator = {
    [@bs.module "react-navigation"]
    external _createStackNavigator:
      Js.Dict.t({. "screen": ReasonReact.reactClass}) =>
      ReasonReact.reactElement =
      "createStackNavigator";

    let stackConfig =
      List.map(
        r => {
          let (name, conf) = Config.mapRoute(r);

          (name, routeConfigurationToJs(conf));
        },
        Config.routes,
      )
      |> Js.Dict.fromList;

    let navigatorComponent = _createStackNavigator(stackConfig);
  };
};
