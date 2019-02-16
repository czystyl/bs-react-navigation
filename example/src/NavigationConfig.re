/* open BsReactNavigation;

   module Config = {
     /*
        type of each route
      */
     type route = [ | `Home | `Details(int)];

     /*
       List of routes with default params
      */
     let routes = [`Home, `Details(1)];
   };

   include Stack.Configure(Config); */

type listType = [ | `A | `B(int) | `C(string)];

[@bs.deriving abstract]
type n = {p: unit => unit};

type r('n, 'p) = {
  nn: 'n,
  pp: 'p,
};

[@bs.deriving abstract]
/* Instead of string/int I want to get type from variants */
type c = {
  p: int,
  s: (n, string) => r(n, string),
};

type gs = listType => c;

let g = (a: listType) =>
  /* argument ~p of type c should be diffrent, depends on variant */
  switch (a) {
  | `A => c(~p=1, ~s=(cn, p) => {nn: cn, pp: p})
  /* p: int */
  | `B(p) => c(~p, ~s=(cn, p) => {nn: cn, pp: p})
  /* p: string */
  | `C(p) => c(~p, ~s=(cn, p) => {nn: cn, pp: p})
  };
