type routeConfiguration = {screen: ReasonReact.reactClass};

type navigatorConfig = {initialRouteName: string};

module type Configuration = {
  type routes;
  let navigatorConfig: navigatorConfig;
  let routes: list(routes);
  let mapRoute: routes => (string, routeConfiguration);
};

module CreateStackNavigator:
  (Config: Configuration) =>
   {module StackNavigator: {let navigator: ReasonReact.reactElement;};};
