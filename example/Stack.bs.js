'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Js_option = require("bs-platform/lib/js/js_option.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var ReactNavigation = require("react-navigation");

function Create(Config) {
  var State = /* module */[];
  var getParams = function (t) {
    return t.state.params;
  };
  var NavigationProp = /* module */[
    /* State */State,
    /* getParams */getParams
  ];
  var ScreenOptions = /* module */[];
  var containerDisplayName = "$ReRoute_Container";
  var makeNavigationProp = function (navigation) {
    return /* record */[
            /* push */(function (route) {
                navigation.push(containerDisplayName, {
                      route: route
                    });
                return /* () */0;
              }),
            /* pop */(function (_route) {
                return /* () */0;
              })
          ];
  };
  var getCurrentScreen = function (navigation) {
    var params = Js_option.getExn(navigation.state.params);
    var nav = makeNavigationProp(navigation);
    return Curry._2(Config[/* render */1], params.route, nav);
  };
  var component = ReasonReact.statelessComponent("StackContainer");
  var make = function (navigation, _children) {
    return /* record */[
            /* debugName */component[/* debugName */0],
            /* reactClassInternal */component[/* reactClassInternal */1],
            /* handedOffState */component[/* handedOffState */2],
            /* willReceiveProps */component[/* willReceiveProps */3],
            /* didMount */component[/* didMount */4],
            /* didUpdate */component[/* didUpdate */5],
            /* willUnmount */component[/* willUnmount */6],
            /* willUpdate */component[/* willUpdate */7],
            /* shouldUpdate */component[/* shouldUpdate */8],
            /* render */(function (_self) {
                return getCurrentScreen(navigation)[0];
              }),
            /* initialState */component[/* initialState */10],
            /* retainedProps */component[/* retainedProps */11],
            /* reducer */component[/* reducer */12],
            /* jsElementWrapped */component[/* jsElementWrapped */13]
          ];
  };
  var Container = /* module */[
    /* component */component,
    /* make */make
  ];
  var route = {
    params: {
      route: Config[/* initialRoute */0]
    },
    screen: (function (options) {
        return ReasonReact.element(undefined, undefined, make(options.navigation, /* array */[]));
      }),
    navigationOptions: (function (options) {
        return getCurrentScreen(options.navigation)[1];
      })
  };
  var routes = { };
  routes[containerDisplayName] = route;
  var $$navigator = ReactNavigation.createAppContainer(ReactNavigation.createStackNavigator(routes, {
            initialRouteName: containerDisplayName
          }));
  return /* module */[
          /* NavigationProp */NavigationProp,
          /* ScreenOptions */ScreenOptions,
          /* containerDisplayName */containerDisplayName,
          /* makeNavigationProp */makeNavigationProp,
          /* getCurrentScreen */getCurrentScreen,
          /* Container */Container,
          /* route */route,
          /* routes */routes,
          /* navigator */$$navigator
        ];
}

exports.Create = Create;
/* ReasonReact Not a pure module */
