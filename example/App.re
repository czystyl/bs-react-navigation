open Config;

module StackNavigator = Stack.Create({
  type route = Config.route;
  let initialRoute = Details("5");
  let render = (route, navigation) => 
    switch (route) {
    | Home => <Home navigation text="" />
    | Details(userId) => <Home navigation text={"Hello " ++ userId} />
    }
});

let reactClass = StackNavigator.navigator;