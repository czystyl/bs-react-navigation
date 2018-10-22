module type Configuration = {
  type routes;
  type routeConfig = {screen: ReasonReact.reactClass};
  let routes: list(routes);
  let mapRoute: routes => (string, routeConfig);
};
module CreateStackNavigator:
  (Config: Configuration) =>
   {
    module StackNavigator: {
      let generateJsStackNavigatorConfig: Js.Dict.t(Config.routeConfig);
    };
  };
