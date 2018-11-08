open Navigation;

let mapRoute: StackNavigator.mapRoute =
  r =>
    switch (r) {
    | Home => ("Home", {screen: navigation => <Home navigation />})
    | Details => ("Details", {screen: navigation => <Details navigation />})
    };

let reactClass = StackNavigator.navigator(mapRoute);