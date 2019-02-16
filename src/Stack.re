[@bs.module "react-navigation"]
external _createStackNavigator: ('a, 'b) => ReasonReact.reactElement =
  "createStackNavigator";

[@bs.module "react-navigation"]
external _createAppContainer: 'a => ReasonReact.reactElement =
  "createAppContainer";

module type Configuration = {
  type route;

  let routes: list(route);
};

module Configure = (Config: Configuration) => {
  module Navigation = {
    type t = {push: Config.route => unit};
  };
  [@bs.deriving abstract]
  type config = {screen: Navigation.t => ReasonReact.reactElement};

  type getScreen = Config.route => config;

  let make = (getScreen: getScreen) => {
    Js.log(Config.routes);

    let routes =
      List.map(
        route => {
          let component = getScreen(route);

          Js.log(component);

          ();
        },
        Config.routes,
      );

    1;
  };
};
