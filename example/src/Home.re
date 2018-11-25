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
        <Button
          title="Go to details screen with no params"
          onPress={() => navigation.push(Details(None))}
        />
        <Text>
          {ReasonReact.string("Home screen key: " ++ navigation.state.key)}
        </Text>
      </View>
    </SafeAreaView>,
};
