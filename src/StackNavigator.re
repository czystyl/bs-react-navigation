[@bs.deriving jsConverter]
type state = {key: string};

type navigation('a) = {
  push: 'a => unit,
  pop: unit => unit,
  state,
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

  module Navigation = {
    type state = {. "key": string};
    type t = {. "state": state};

    [@bs.send] external push: (t, string, routeProps) => unit = "push";

    [@bs.send] external pop: t => unit = "pop";

    [@bs.get] external _getParams: state => option(routeProps) = "params";
    let getParams = nav => _getParams(nav##state);
  };

  module ScreenOptions = {
    type t = {. "navigation": Navigation.t};
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

  let makeNavigationProp = (navigation: Navigation.t) =>
    Navigation.{
      push: route =>
        push(navigation, containerDisplayName, routeProps(~route)),
      pop: () => pop(navigation),
      state: stateFromJs(navigation##state),
    };

  let getCurrentScreen = (navigation: Navigation.t) => {
    /**
     * Params can be `null` in React Navigation, but since we are always
     * declaring them, we can safely access it.
     */
    let params = Navigation.getParams(navigation) |> Js.Option.getExn;
    let nav = makeNavigationProp(navigation);
    Config.getScreen(routeGet(params), nav);
  };

  let route =
    routeConfig(
      ~params=routeProps(~route=Config.initialRoute),
      ~screen=
        (options: ScreenOptions.t) =>
          getCurrentScreen(options##navigation) |> fst,
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