'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var ReactNavigation = require("react-navigation");

function Create(Config) {
  var NavigationProp = /* module */[];
  var ScreenOptions = /* module */[];
  var displayName = "$ReRoute_Container";
  var component = ReasonReact.statelessComponent("StackContainer");
  var make = function (route, navigation, _children) {
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
                var navigation_000 = function (route) {
                  navigation.push(displayName, {
                        route: route
                      });
                  return /* () */0;
                };
                var navigation_001 = function (_route) {
                  return /* () */0;
                };
                var navigation$1 = /* record */[
                  navigation_000,
                  navigation_001
                ];
                return Curry._2(Config[/* render */1], route, navigation$1);
              }),
            /* initialState */component[/* initialState */10],
            /* retainedProps */component[/* retainedProps */11],
            /* reducer */component[/* reducer */12],
            /* jsElementWrapped */component[/* jsElementWrapped */13]
          ];
  };
  var Container = /* module */[
    /* displayName */displayName,
    /* component */component,
    /* make */make
  ];
  var routes = { };
  routes[displayName] = {
    screen: (function (options) {
        return ReasonReact.element(undefined, undefined, make(Config[/* initialRoute */0], options.navigation, /* array */[]));
      })
  };
  var $$navigator = ReactNavigation.createStackNavigator(routes, {
        initialRouteName: displayName
      });
  return /* module */[
          /* NavigationProp */NavigationProp,
          /* ScreenOptions */ScreenOptions,
          /* Container */Container,
          /* routes */routes,
          /* navigator */$$navigator
        ];
}

exports.Create = Create;
/* ReasonReact Not a pure module */
