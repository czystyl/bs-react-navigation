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

type navWithRoute = string => ReasonReact.reactElement;

[@bs.deriving jsConverter]
type routeConfiguration = {screen: navWithRoute};

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
      (
        Js.Dict.t({. "screen": navWithRoute}),
        {. "initialRouteName": string}
      ) =>
      ReasonReact.reactElement =
      "createStackNavigator";

    let routes =
      Config.routes
      |> List.map(route => {
           let (name, configuration) = Config.mapRoute(route);

           let withNavigation = navigation =>
             ReasonReact.element(configuration.screen(~navigation, [||]));

           (name, routeConfigurationToJs({screen: withNavigation}));
         })
      |> Js.Dict.fromList;

    let (initialName, _) =
      Config.mapRoute(Config.navigatorConfig.initialRouteName);

    let sConfig = navigatorConfigToJs({initialRouteName: initialName});
    let navigator = _createSN(routes, sConfig);
  };
};
