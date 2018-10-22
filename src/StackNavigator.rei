type routeConfiguration = {screen: ReasonReact.reactClass};

module type Configuration = {
  type routes;

  let routes: list(routes);
  let mapRoute: routes => (string, routeConfiguration);
};
module CreateStackNavigator:
  (Config: Configuration) =>
   {module StackNavigator: {let navigator: ReasonReact.reactElement;};};
