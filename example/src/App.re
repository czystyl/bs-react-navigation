open BsReactNavigation;

module Config = {
  open StackNavigator;

  type routes =
    | Home
    | Details;

  let navigatorConfig = {initialRouteName: "Home"};

  let routes = [Home, Details];

  let mapRoute = r =>
    switch (r) {
    | Home => ("Home", {screen: Home.reactComponent})
    | Details => ("Details", {screen: Details.reactComponent})
    };
};

include StackNavigator.CreateStackNavigator(Config);

let reactClass = StackNavigator.navigator;
