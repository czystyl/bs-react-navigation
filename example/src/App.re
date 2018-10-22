open BsReactNavigation;

module Config = {
  open StackNavigator;

  type routes =
    | Home
    | Details(string);

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

let reactClass = StackNavigator.navigatorComponent;
