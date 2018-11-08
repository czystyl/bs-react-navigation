open BsReactNative;

module Styles = {
  open Style;

  let container =
    style([
      marginTop(Pt(50.0)),
      alignItems(Center),
      justifyContent(Center),
    ]);
};

let component = ReasonReact.statelessComponent("App");

let make = (~navigation: Navigation.StackNavigator.navigation, _children) => {
  ...component,
  render: _self => {
    let toDetails = (navigation: Navigation.StackNavigator.navigation) =>
      navigation.navigation.navigate(Details);

    <SafeAreaView>
      <View style=Styles.container>
        <Text> {ReasonReact.string("HOME!")} </Text>
        <Button
          title="Go to details screen "
          onPress={() => toDetails(navigation)}
        />
      </View>
    </SafeAreaView>;
  },
};