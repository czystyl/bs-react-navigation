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

let make = (~nav: NavigationConfig.NavigationOptions.t, _children) => {
  ...component,
  render: _self => {
    Js.log(nav);
    <SafeAreaView>
      <View style=Styles.container>
        <Text> {ReasonReact.string("Detail!")} </Text>
        <Button title="Go back" onPress={() => Js.log(123)} />
      </View>
    </SafeAreaView>;
  },
};
