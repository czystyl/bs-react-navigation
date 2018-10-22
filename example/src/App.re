open BsReactNavigation;

module Config = {
  type routes =
    | Home
    | Details(string);

  type routeConfig = {screen: ReasonReact.reactClass};

  type config = {component: ReasonReact.reactClass};

  let routes = [Home, Details("params")];

  let mapRoute = r =>
    switch (r) {
    | Home => (
        "Home",
        {
          screen:
            ReasonReact.wrapReasonForJs(~component=Home.component, Home.make),
        },
      )
    | Details(_) => (
        "Details",
        {
          screen:
            ReasonReact.wrapReasonForJs(
              ~component=Details.component,
              Details.make,
            ),
        },
      )
    };
};

include StackNavigator.CreateStackNavigator(Config);

let reactClass =
  ReasonReact.wrapReasonForJs(~component=Home.component, Home.make);
