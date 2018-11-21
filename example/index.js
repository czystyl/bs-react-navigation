import React from 'react';
import { AppRegistry } from 'react-native';

import { reactClass } from './App.bs.js';

console.ignoredYellowBox = ['Warning: component'];

AppRegistry.registerComponent('ReasonDemo', () => reactClass);