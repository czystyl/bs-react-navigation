type navigation('a) = {
  push: 'a => unit,
  pop: 'a => unit,
};

[@bs.deriving abstract]
type screenOptions = {
  [@bs.optional]
  title: string,
};

module type StackConfig = {
  type route;
  let initialRoute: route;
  let getScreen:
    (route, navigation(route)) => (ReasonReact.reactElement, screenOptions);
};

module Create = (Config: StackConfig) => {
  [@bs.deriving abstract]
  type navigatorConfig = {initialRouteName: string};

  [@bs.deriving abstract]
  type routeProps = {route: Config.route};

  module NavigationProp = {
    type state;
    type t = {. "state": state};

    [@bs.send] external push: (t, string, routeProps) => unit = "push";

    [@bs.get] external _getParams: state => option(routeProps) = "params";
    let getParams = nav => _getParams(nav##state);
  };

  module ScreenOptions = {
    type t = {. "navigation": NavigationProp.t};
  };

  [@bs.deriving abstract]
  type routeConfig = {
    params: routeProps,
    screen: ScreenOptions.t => ReasonReact.reactElement,
    navigationOptions: ScreenOptions.t => screenOptions,
  };

  [@bs.module "react-navigation"]
  external _createStackNavigator:
    (Js.Dict.t(routeConfig), navigatorConfig) => ReasonReact.reactElement =
    "createStackNavigator";

  [@bs.module "react-navigation"]
  external _createAppContainer:
    ReasonReact.reactElement => ReasonReact.reactElement =
    "createAppContainer";

  let containerDisplayName = "$ReRoute_Container";

  let makeNavigationProp = (navigation: NavigationProp.t) => {
    push: route =>
      NavigationProp.push(
        navigation,
        containerDisplayName,
        routeProps(~route),
      ),
    pop: _route => (),
  };

  let getCurrentScreen = (navigation: NavigationProp.t) => {
    /** Params can be `null` in React Navigation, but we are always declaring them */
    let params = NavigationProp.getParams(navigation) |> Js.Option.getExn;
    let nav = makeNavigationProp(navigation);
    Config.getScreen(routeGet(params), nav);
  };

  module Container = {
    let component = ReasonReact.statelessComponent("StackContainer");

    let make = (~navigation: NavigationProp.t, _children) => {
      ...component,
      render: _self => getCurrentScreen(navigation) |> fst,
    };
  };

  let route =
    routeConfig(
      ~params=routeProps(~route=Config.initialRoute),
      ~screen=
        (options: ScreenOptions.t) =>
          <Container navigation=options##navigation />,
      ~navigationOptions=
        (options: ScreenOptions.t) =>
          getCurrentScreen(options##navigation) |> snd,
    );

  let routes = Js.Dict.empty();
  Js.Dict.set(routes, containerDisplayName, route);

  let navigator =
    _createAppContainer(
      _createStackNavigator(
        routes,
        navigatorConfig(~initialRouteName=containerDisplayName),
      ),
    );
};