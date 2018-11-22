'use strict';

var ReasonReact = require("reason-react/src/ReasonReact.js");
var Home$BsReactNavigation = require("./Home.bs.js");
var Stack$BsReactNavigation = require("./Stack.bs.js");

function render(route, navigation) {
  if (route) {
    var userId = route[0];
    return /* tuple */[
            ReasonReact.element(undefined, undefined, Home$BsReactNavigation.make(navigation, "Hello " + userId, /* array */[])),
            {
              title: "Home " + userId
            }
          ];
  } else {
    return /* tuple */[
            ReasonReact.element(undefined, undefined, Home$BsReactNavigation.make(navigation, "", /* array */[])),
            {
              title: "Home"
            }
          ];
  }
}

var StackNavigator = Stack$BsReactNavigation.Create(/* module */[
      /* initialRoute : Details */["5"],
      /* render */render
    ]);

var reactClass = StackNavigator[/* navigator */7];

exports.StackNavigator = StackNavigator;
exports.reactClass = reactClass;
/* StackNavigator Not a pure module */
