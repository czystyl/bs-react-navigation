let createStackNavigator = [%raw
  {|
  function(componment, second){
    const React = require('react');
    const RNav = require('react-navigation');

    const RootStack = RNav.createStackNavigator({
      1: {
        screen: componment
      },
      0: {
        screen: second
      }
    },
    {
      initialRouteName: "0",
    }
    );

    return class App extends React.Component {
      render() {
        return <RootStack />;
      }
    }
  }
|}
];