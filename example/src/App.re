open NavigationConfig;

let mapRoute: Navigator.mapRoute =
  r =>
    switch (r) {
    | Home => ("Home", {screen: navigation => <Home navigation />})
    | Details => ("Details", {screen: navigation => <Details navigation />})
    };

let reactClass = Navigator.configure(mapRoute);
