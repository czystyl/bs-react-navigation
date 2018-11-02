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

let make = (~navigation: string, _children) => {
  ...component,
  render: _self => {
    Js.log2("1elo", navigation);

    <SafeAreaView>
      <View style=Styles.container>
        <Text> {ReasonReact.string("HOME")} </Text>
      </View>
    </SafeAreaView>;
  },
};
