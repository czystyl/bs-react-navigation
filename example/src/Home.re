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
type params = string;

let make = (~navigation: Navigation.StackNavigator.navigation, _children) => {
  ...component,
  render: _self => {
    let toDetails = (navigation: Navigation.StackNavigator.navigation) =>
      navigation.navigation.navigate(Details);

    <SafeAreaView>
      <View style=Styles.container>
        <Text> {ReasonReact.string("HOME!")} </Text>
        <Text> {ReasonReact.string(string_of_int(1))} </Text>
        <Button
          title="Go to details screen "
          onPress={() => nav.push("Details")}
        />
      </View>
    </SafeAreaView>;
  },
};
