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
    | Home => ("Home", {screen: navigation => <Home navigation />})
    | Details => ("Details", {screen: navigation => <Details navigation />})
    };
};

include StackNavigator.CreateStackNavigator(Config);

let reactClass = StackNavigator.navigator;
