
type component =
  ReasonReact.componentSpec(
    ReasonReact.stateless,
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );
type make =
  unit =>
  ReasonReact.componentSpec(
    ReasonReact.stateless,
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );

type screen = (component, make);
type configureRoute = {screen};

[@bs.deriving jsConverter]
type routeConfiguration = {screen: ReasonReact.reactClass};

[@bs.deriving jsConverter]
type navigatorConfig('a) = {initialRouteName: 'a};

module type Configuration = {
  type routes;
  let navigatorConfig: navigatorConfig(routes);
  let routes: list(routes);
  let mapRoute: routes => (string, configureRoute);
};

module CreateStackNavigator = (Config: Configuration) => {
  module StackNavigator = {
    [@bs.module "react-navigation"]
    external _createSN:
      (Js.Dict.t({. "screen": ReasonReact.reactClass}), {. "initialRouteName": string}) =>
      ReasonReact.reactElement =
      "createStackNavigator";

    let routes =
      Config.routes
      |> List.map(route => {
           let (name, configuration) = Config.mapRoute(route);

           let (component, make) = configuration.screen;
           let wrapp = ReasonReact.wrapReasonForJs(~component, make);
          

           (name, routeConfigurationToJs({screen: wrapp}));
         })
      |> Js.Dict.fromList;

    let (initialName, _) =
      Config.mapRoute(Config.navigatorConfig.initialRouteName);

    let sConfig = navigatorConfigToJs({initialRouteName: initialName});
    let navigator = _createSN(routes, sConfig);
  };
};
