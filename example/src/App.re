open BsReactNavigation;

let navigationConfig =
  StackNavigator.navigatorConfig(~initialRouteName="Detail");

let reactClass =
  StackNavigator.create(
    ~routes=[
      ("Home", StackNavigator.routeConfig(~screen=() => <Home />)),
      ("Detail", StackNavigator.routeConfig(~screen=() => <Detail />)),
    ],
    ~navigatorConfig=navigationConfig,
  );