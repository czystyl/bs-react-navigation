/* type t;

   [@bs.deriving abstract]
   type routeConfig = {screen: ReasonReact.reactElement};

   [@bs.deriving abstract]
   type navigatorConfig = {initialRouteName: string};

   type route = (string, routeConfig);

   type routes = list(route);

   let create:
     (~routes: routes, ~navigatorConfig: navigatorConfig) =>
     ReasonReact.reactElement;

   let _create: (ReasonReact.reactClass, ReasonReact.reactClass) => string; */