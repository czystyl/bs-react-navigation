'use strict';

var ReasonReact = require("reason-react/src/ReasonReact.js");
var Home$BsReactNavigation = require("./Home.bs.js");
var Stack$BsReactNavigation = require("./Stack.bs.js");

function render(route, navigation) {
  if (route) {
    return ReasonReact.element(undefined, undefined, Home$BsReactNavigation.make(navigation, "Hello " + route[0], /* array */[]));
  } else {
    return ReasonReact.element(undefined, undefined, Home$BsReactNavigation.make(navigation, "", /* array */[]));
  }
}

var StackNavigator = Stack$BsReactNavigation.Create(/* module */[
      /* initialRoute : Details */["5"],
      /* render */render
    ]);

var reactClass = StackNavigator[/* navigator */4];

exports.StackNavigator = StackNavigator;
exports.reactClass = reactClass;
/* StackNavigator Not a pure module */
