type t;

[@bs.deriving abstract]
type routeConfig = {screen: unit => ReasonReact.reactElement};

[@bs.deriving abstract]
type navigatorConfig = {initialRouteName: string};

type route = (string, routeConfig);

type routes = list(route);

[@bs.module "react-navigation"]
external _createStackNavigator:
  (Js.Dict.t(routeConfig), navigatorConfig) => ReasonReact.reactElement =
  "createStackNavigator";

let create = (~routes: routes, ~navigatorConfig: navigatorConfig) => {
  let jsRoutes = routes |> Js.Dict.fromList;

  _createStackNavigator(jsRoutes, navigatorConfig);
};