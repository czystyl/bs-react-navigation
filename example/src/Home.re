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
type params = string;

let make = (~navigation: Navigator.navigationProp, _children) => {
  ...component,
  render: _self =>
    <SafeAreaView>
      <View style=Styles.container>
        <Text> {ReasonReact.string("HOME!")} </Text>
        <Text> {ReasonReact.string(string_of_int(1))} </Text>
        <Button
          title="Go to details screen "
          onPress={() => navigation.push(Details(Some("Simea")))}
        />
      </View>
    </SafeAreaView>,
};
