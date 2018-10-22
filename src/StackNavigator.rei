type routeConfiguration = {screen: ReasonReact.reactClass};

module type Configuration = {
  type routes;
  type routeConfig;
  let routes: list(routes);
  let mapRoute: routes => (string, routeConfiguration);
};
module CreateStackNavigator:
  (Config: Configuration) =>
   {module StackNavigator: {let navigatorComponent: ReasonReact.reactElement;};
  };
