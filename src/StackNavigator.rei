type navigatorConfig('a) = {initialRouteName: 'a};

type configureRoute = {screen: string => ReasonReact.reactElement};

module type Configuration = {
  type routes;

  let navigatorConfig: navigatorConfig(routes);
  let routes: list(routes);
  let mapRoute: routes => (string, configureRoute);
};

module CreateStackNavigator:
  (Config: Configuration) =>
   {module StackNavigator: {let navigator: ReasonReact.reactElement;};};
