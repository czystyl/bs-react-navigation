type t;

[@bs.deriving abstract]
type createRoute = {screen: unit => ReasonReact.reactElement};

[@bs.deriving abstract]
type createNavigationConfig = {initialRouteName: string};

type routes = list((string, createRoute));

[@bs.module "react-navigation"]
external _createStackNavigator:
  (Js.Dict.t(createRoute), createNavigationConfig) => ReasonReact.reactElement =
  "createStackNavigator";

let create = (~routes: routes, ~navigatorConfig: createNavigationConfig) => {
  let jsRoutes = routes |> Js.Dict.fromList;

  _createStackNavigator(jsRoutes, navigatorConfig);
};