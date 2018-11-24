open BsReactNavigation;

module Config = {
  type route =
    | Home
    | Details(option(string));

  let routes = [Home, Details(None)];
};

include Stack.Make(Config);
