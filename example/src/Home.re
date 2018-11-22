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

let make = (~nav: NavigationConfig.NavigationOptions.t, _children) => {
  ...component,
  render: _self => {
    Js.log2("elo", nav);

    <SafeAreaView>
      <View style=Styles.container>
        <Text> {ReasonReact.string("HOME!")} </Text>
        <Text> {ReasonReact.string(string_of_int(1))} </Text>
        <Button
          title="Go to details screen "
          onPress={
            () => {
              let na = nav##navigation##push;
              na("Details");
              /* nav##navigation##push("siema"); */
            }
          }
        />
      </View>
    </SafeAreaView>;
  },
};

/* let reactComponent =
   ReasonReact.wrapReasonForJs(~component, () =>
     make(~nav={"navigation": "string"}, [||])
   ); */
