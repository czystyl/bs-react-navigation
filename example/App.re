open Config;

module StackNavigator =
  Stack.Create({
    open Stack;

    type route = Config.route;
    let initialRoute = Details("5");

    let getScreen = (route, navigation) =>
      switch (route) {
      | Home => (<Home navigation text="" />, options(~title="Home", ()))
      | Details(userId) => (
          <Home navigation text={"Hello " ++ userId} />,
          options(~title="Home " ++ userId, ()),
        )
      };
  });

let reactClass = StackNavigator.navigator;