open BsReactNavigation;

module Config = {
  open StackNavigator;

  type routes =
    | Home
    | Details;

  let navigatorConfig = {initialRouteName: Home};

  let routes = [Home, Details];

  let mapRoute = r =>
    switch (r) {
    | Home => ("Home", {screen: Home.make})
    | Details => ("Details", {screen: Details.make})
    };
};

include StackNavigator.CreateStackNavigator(Config);
let reactClass = StackNavigator.navigator;
