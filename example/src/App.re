open BsReactNavigation;

let navigationConfig =
  StackNavigator.createNavigationConfig(~initialRouteName="Home");

let routes = [
  ("Home", StackNavigator.createRoute(~screen=() => <Home />)),
  ("Detail", StackNavigator.createRoute(~screen=() => <Detail />)),
];

let reactClass =
  StackNavigator.create(~routes, ~navigatorConfig=navigationConfig);