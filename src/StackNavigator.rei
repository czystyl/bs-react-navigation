type component =
  ReasonReact.componentSpec(
    ReasonReact.stateless,
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );
type make =
  (~navigation: string, array(ReasonReact.reactElement)) =>
  ReasonReact.componentSpec(
    ReasonReact.stateless,
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );

type configureRoute = {screen: make};

type navigatorConfig('a) = {initialRouteName: 'a};

module type Configuration = {
  type routes;
  let navigatorConfig: navigatorConfig(routes);
  let routes: list(routes);
  let mapRoute: routes => (string, configureRoute);
};

module CreateStackNavigator:
  (Config: Configuration) =>
   {module StackNavigator: {let navigator: ReasonReact.reactElement;};};
