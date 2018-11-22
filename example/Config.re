type route =
  | Home
  | Details(string);
type navigation = StackNavigator.navigation(route);