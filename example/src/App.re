open BsReactNative;
module Styles = {
  open Style;

  let container =
    style([
      backgroundColor(String("red")),
      alignItems(Center),
      justifyContent(Center),
    ]);
};

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <SafeAreaView>
      <View style=Styles.container>
        <Text> {ReasonReact.string("Welcome to bs-react-navigation")} </Text>
      </View>
    </SafeAreaView>,
};

let reactClass = ReasonReact.wrapReasonForJs(~component, make);