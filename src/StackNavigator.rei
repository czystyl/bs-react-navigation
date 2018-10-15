type t;

[@bs.deriving abstract]
type createRoute = {screen: unit => ReasonReact.reactElement};

[@bs.deriving abstract]
type createNavigationConfig = {initialRouteName: string};

type routes = list((string, createRoute));

let create:
  (~routes: routes, ~navigatorConfig: createNavigationConfig) =>
  ReasonReact.reactElement;