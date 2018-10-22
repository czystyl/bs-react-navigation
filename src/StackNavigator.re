module type Configuration = {
  type routes;
  type routeConfig = {screen: ReasonReact.reactClass};

  let routes: list(routes);
  let mapRoute: routes => (string, routeConfig);
};

module CreateStackNavigator = (Config: Configuration) => {
  module StackNavigator = {
    [@bs.module "react-navigation"]
    external _createStackNavigator:
      Js.Dict.t(Config.routes) => ReasonReact.reactElement =
      "createStackNavigator";

    let generateJsStackNavigatorConfig =
      Config.routes |> List.map(Config.mapRoute) |> Js.Dict.fromList;

    Js.log(generateJsStackNavigatorConfig);
  };
};
