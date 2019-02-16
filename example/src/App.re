/* open NavigationConfig;

   let getScreen = (route: Config.route) =>
     switch (route) {
     | `Home => config(~screen=nav => <Home navigation=nav params="123" />)
     | `Details(params) =>
       config(~screen=nav => <Details navigation=nav params />)
     };

   let a = make(getScreen);

   let app = Home.render; */

type nV = {p: unit => unit};

type r('a, 'b) = {
  n: 'a,
  p: 'b,
};

type c('a) = {s: (nV, 'a) => r(nV, 'a)};
