/**
 * Route and Navigation types are kept in a separate module to
 * handle circular references between modules
 */
open Config;

module Stack =
  StackNavigator.Create({
    open StackNavigator;

    /**
     * StackNavigator requires `route` type to be defined.
     */
    type route = Config.route;

    /**
     * Initial route to start with. Has to be one of `route` variants.
     */
    let initialRoute = Details("Mike");

    /**
     * Returns a screen for a given route and its options
     */
    let getScreen = (route, navigation) =>
      switch (route) {
      | Home => (<Screen navigation />, screenOptions(~title="Home", ()))
      | Details(userId) => (
          <Screen navigation text={"Browsing profile of: " ++ userId} />,
          screenOptions(~title="Hello " ++ userId, ()),
        )
      };
  });

/**
 * Exporting application entry-point, see `index.js` for details
 */
let app = Stack.navigator;