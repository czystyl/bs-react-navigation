type navigatorConfig('a) = {initialRouteName: 'a};

module type Configuration = {
  type routes;

  let navigatorConfig: navigatorConfig(routes);
  let routes: list(routes);
};

module CreateStackNavigator:
  (Config: Configuration) =>
   {
    module StackNavigator: {
      [@bs.deriving {jsConverter: newType}]
      type navigationProps = {
        navigate: Config.routes => unit,
        goBack: unit => unit,
      };

      type navigation = {navigation: navigationProps};

      type configureRoute = {screen: navigation => ReasonReact.reactElement};

      type mapRoute = Config.routes => (string, configureRoute);

      let navigator: mapRoute => ReasonReact.reactElement;
    };
  };
