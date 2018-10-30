type routeConfiguration = {screen: ReasonReact.reactClass};

type navigatorConfig('a) = {initialRouteName: 'a};

module type Configuration = {
  type routes;
  let navigatorConfig: navigatorConfig(routes);
  let routes: list(routes);
  let mapRoute: routes => (string, routeConfiguration);
};

module CreateStackNavigator:
  (Config: Configuration) =>
   {module StackNavigator: {let navigator: ReasonReact.reactElement;};};
