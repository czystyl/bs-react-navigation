// Generated by BUCKLESCRIPT VERSION 4.0.6, PLEASE EDIT WITH CARE
'use strict';

var Home = require("./Home.js");
var Details = require("./Details.js");
var StackNavigator$BsReactNavigation = require("bs-react-navigation/lib/js/src/StackNavigator.js");

function mapRoute(r) {
  if (r) {
    return /* tuple */[
            "Details",
            /* record */[/* screen */Details.reactComponent]
          ];
  } else {
    return /* tuple */[
            "Home",
            /* record */[/* screen */Home.reactComponent]
          ];
  }
}

var Config_000 = /* navigatorConfig : record */[/* initialRouteName : Details */1];

var Config_001 = /* routes : :: */[
  /* Home */0,
  /* :: */[
    /* Details */1,
    /* [] */0
  ]
];

var Config = /* module */[
  Config_000,
  Config_001,
  /* mapRoute */mapRoute
];

var include = StackNavigator$BsReactNavigation.CreateStackNavigator(Config);

var StackNavigator = include[0];

var reactClass = StackNavigator[/* navigator */0];

exports.Config = Config;
exports.StackNavigator = StackNavigator;
exports.reactClass = reactClass;
/* include Not a pure module */
