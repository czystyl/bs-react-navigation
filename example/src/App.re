open BsReactNavigation;

module Config = {
  open StackNavigator;

  type routes =
    | Home
    | Details;

  let navigatorConfig = {initialRouteName: Details};

  let routes = [Home, Details];

  let mapRoute = r =>
    switch (r) {
    | Home => ("Home", {screen: (Home.component, Home.make)})
    | Details => ("Details", {screen: (Details.component, Details.make)})
    };
};

include StackNavigator.CreateStackNavigator(Config);
let reactClass = StackNavigator.navigator;
