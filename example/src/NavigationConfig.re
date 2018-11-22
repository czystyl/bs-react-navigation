open BsReactNavigation;

open Stack;
type rou =
  | Home
  | Details;
module Config = {
  type route = rou;

  let routes = [Home, Details];
};

include Stack.Make(Config);
