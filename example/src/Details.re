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
  render: _self => {
    let getRandStr = string_of_int(Random.int(1123));
    let title = "Go to details screen with params" ++ getRandStr;

    <SafeAreaView>
      <View style=Styles.container>
        <Text>
          {ReasonReact.string("Params : " ++ navigation.state.params)}
        </Text>
        <Button
          title
          onPress={
            () => navigation.push(Details(Some("Params " ++ getRandStr)))
          }
        />
        <Button title="Go back" onPress={() => navigation.goBack()} />
        <Text>
          {ReasonReact.string("Details screen key: " ++ navigation.state.key)}
        </Text>
      </View>
    </SafeAreaView>;
  },
};
