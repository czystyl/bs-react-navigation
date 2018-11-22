open BsReactNavigation;

module Config = {
  open StackNavigator;

  type routes =
    | Home
    | Details;

  let navigatorConfig = {initialRouteName: Home};

  let routes = [Home, Details];
};

include StackNavigator.CreateStackNavigator(Config);