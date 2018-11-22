[@bs.deriving jsConverter]
type navigatorConfig('a) = {initialRouteName: 'a};

module type Configuration = {
  type routes;

  let navigatorConfig: navigatorConfig(routes);
  let routes: list(routes);
};

module CreateStackNavigator = (Config: Configuration) => {
  module StackNavigator = {
    [@bs.deriving {jsConverter: newType}]
    type navigationProps = {
      navigate: Config.routes => unit,
      goBack: unit => unit,
    };

    [@bs.deriving {jsConverter: newType}]
    type navigationRecord = {navigation: abs_navigationProps};

    type navigation = {navigation: navigationProps};

    type configureRoute = {screen: navigation => ReasonReact.reactElement};

    type mapRoute = Config.routes => (string, configureRoute);

    type navWithRoute = abs_navigationRecord => ReasonReact.reactElement;

    [@bs.deriving jsConverter]
    type routeConfiguration = {
      screen: abs_navigationRecord => ReasonReact.reactElement,
    };

    /* Bindings to the createStackNavigator */
    [@bs.module "react-navigation"]
    external _createStackNavigator:
      (
        Js.Dict.t({. "screen": navWithRoute}),
        {. "initialRouteName": string}
      ) =>
      ReasonReact.reactElement =
      "createStackNavigator";

    /* React class navigator */
    let navigator = (mapRoute: mapRoute) => {
      /* Initial configuration */
      let (initialRouteName, _) =
        mapRoute(Config.navigatorConfig.initialRouteName);

      /* List of routes transformed to the JS object with {key: value} */
      let routes =
        Config.routes
        |> List.map(route => {
             let (name, routeConfig) = mapRoute(route);

             let screen = navigation => {
               let wholeNavigation = navigationRecordFromJs(navigation);
               let jsApiNavigationProps =
                 navigationPropsFromJs(wholeNavigation.navigation);
               let reasonApiNavigationProps = {
                 ...jsApiNavigationProps,
                 navigate: route => {
                   let (stringRoute, _) = mapRoute(route);

                   let navigateToRoute: string => unit = [%bs.raw
                     {| function (route) {
                     navigation.navigation.navigate(route)
                    }
                    |}
                   ];

                   navigateToRoute(stringRoute);
                   ();
                 },
               };

               routeConfig.screen({navigation: reasonApiNavigationProps});
             };

             (name, routeConfigurationToJs({screen: screen}));
           })
        |> Js.Dict.fromList;

      _createStackNavigator(
        routes,
        navigatorConfigToJs({initialRouteName: initialRouteName}),
      );
    };
  };
};
