open BsReactNative;
open NavigationConfig;
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

let make = (~navigation: Navigator.navigationProp, _children) => {
  ...component,
  render: _self =>
    <SafeAreaView>
      <View style=Styles.container>
        <Text> {ReasonReact.string("Detail!")} </Text>
        <Button title="Go back" onPress={() => navigation.goBack()} />
      </View>
    </SafeAreaView>,
};