open NavigationConfig;

let mapRoute: Navigator.mapRoute =
  r =>
    switch (r) {
    | Home => ("Home", {screen: nav => <Home nav />})
    | Details => ("Details", {screen: nav => <Details nav />})
    };

let navig = Navigator.configure(mapRoute, Home);

let reactClass = navig;
