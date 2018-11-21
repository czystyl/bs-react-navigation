type navigation('a) = {
  push: 'a => unit,
  pop: 'a => unit
};

module type StackConfig = {
  type route;
  let initialRoute: route;
  let render: (route, navigation(route)) => ReasonReact.reactElement;
};

module Create = (Config: StackConfig) => {
  [@bs.deriving abstract]
  type navigatorConfig = {initialRouteName: string};

  [@bs.deriving abstract]
  type screenProps = {route: Config.route};

  module NavigationProp = {
    type t;
    [@bs.send]
    external push: (t, string, screenProps) => unit = "push";
  };

  module ScreenOptions = {
    type t = Js.t({
      .
      navigation: NavigationProp.t
    });
  };

  [@bs.module "react-navigation"]
  external _createStackNavigator:
    (
      Js.Dict.t({. "screen": ScreenOptions.t => ReasonReact.reactElement}),
      navigatorConfig
    ) =>
    ReasonReact.reactElement =
    "createStackNavigator";

  module Container = {
    let displayName = "$ReRoute_Container";

    let component = ReasonReact.statelessComponent("StackContainer");

    let make = (~route, ~navigation: NavigationProp.t, _children) => {
      ...component,
      render: _self => {
        let navigation: navigation(Config.route) = {
          push: (route) => NavigationProp.push(navigation, displayName, screenProps(~route)),
          pop: (_route) => ()
        };
        Config.render(route, navigation)
      }
    };
  };

  let routes = Js.Dict.empty();
  Js.Dict.set(routes, Container.displayName, { "screen": (options: ScreenOptions.t) => <Container route=Config.initialRoute navigation=options##navigation />});

  let navigator = 
    _createStackNavigator(
      routes,
      navigatorConfig(~initialRouteName=Container.displayName),
    );
};