type navigation('a) = {
  push: 'a => unit,
  pop: 'a => unit,
};

[@bs.deriving abstract]
type options = {
  [@bs.optional]
  title: string,
};

module type StackConfig = {
  type route;
  let initialRoute: route;
  let render:
    (route, navigation(route)) => (ReasonReact.reactElement, options);
};

module Create = (Config: StackConfig) => {
  [@bs.deriving abstract]
  type navigatorConfig = {initialRouteName: string};

  [@bs.deriving abstract]
  type screenProps = {route: Config.route};

  module NavigationProp = {
    type t;

    module State = {
      type t;

      [@bs.get] external getParams: t => option(screenProps) = "params";
    };

    [@bs.send] external push: (t, string, screenProps) => unit = "push";

    [@bs.get "state"] external getState: t => State.t = "";

    let getParams = t => getState(t) |> State.getParams;
  };

  module ScreenOptions = {
    type t = {. "navigation": NavigationProp.t};
  };

  [@bs.deriving abstract]
  type routeConfig = {
    params: screenProps,
    screen: ScreenOptions.t => ReasonReact.reactElement,
    navigationOptions: ScreenOptions.t => options,
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
        screenProps(~route),
      ),
    pop: _route => (),
  };

  module Container = {
    let component = ReasonReact.statelessComponent("StackContainer");

    let make = (~navigation: NavigationProp.t, _children) => {
      ...component,
      render: _self => {
        let params = NavigationProp.getParams(navigation) |> Js.Option.getExn;
        Config.render(routeGet(params), makeNavigationProp(navigation)) |> fst;
      },
    };
  };

  let route =
    routeConfig(
      ~params=screenProps(~route=Config.initialRoute),
      ~screen=
        (options: ScreenOptions.t) =>
          <Container navigation=options##navigation />,
      ~navigationOptions=
        (options: ScreenOptions.t) => {
          let params = NavigationProp.getParams(options##navigation) |> Js.Option.getExn;
          Config.render(routeGet(params), makeNavigationProp(options##navigation)) |> snd;
        },
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