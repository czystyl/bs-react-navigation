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

let make = _children => {
  ...component,
  render: _self =>
    <SafeAreaView>
      <View style=Styles.container>
        <Text>
          {
            ReasonReact.string(
              BsReactNavigation.Navigation.greeting("bs-react-navigations"),
            )
          }
        </Text>
      </View>
    </SafeAreaView>,
};

let reactClass = ReasonReact.wrapReasonForJs(~component, make);