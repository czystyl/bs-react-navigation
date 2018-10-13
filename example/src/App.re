let component = ReasonReact.statelessComponent("Home");

let reactClass =
  BsReactNavigation.Navigation.createStackNavigator(
    Home.reactClass,
    Detail.reactClass,
  );

/* let reactClass = nav(Home.reactClass, Detail.reactClass); */
/* let reactClass = Detail.reactClass; */