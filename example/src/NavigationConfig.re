open BsReactNavigation;

module Config = {
  type route =
    | Home
    | Details;

  let routes = [Home, Details];
};

include Stack.Make(Config);
