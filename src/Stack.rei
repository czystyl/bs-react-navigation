module type Configuration = {
  type route;
  let routes: list(route);
};
module Make:
  (Config: Configuration) =>
   {
    module NavigationProp: {type t;};
    module NavigationOptions: {type t = {. "navigation": NavigationProp.t};};
    module Navigator: {
      type configureRoute = {
        screen: NavigationOptions.t => ReasonReact.reactElement,
      };
      let configureRouteToJs:
        configureRoute =>
        {. "screen": NavigationOptions.t => ReasonReact.reactElement};
      let configureRouteFromJs:
        {.. "screen": NavigationOptions.t => ReasonReact.reactElement} =>
        configureRoute;
      type mapRoute = Config.route => (string, configureRoute);

      let configure: (mapRoute, Config.route) => ReasonReact.reactElement;
    };
  };
