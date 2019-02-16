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

let make = (~navigation, ~params: params, _children) => {
  ...component,
  render: _self => {
    Js.log(navigation);
    Js.log(params);

    <SafeAreaView>
      <View style=Styles.container>
        /* <Button
             title="Go to details screen with no params"
             onPress={() => navigation.push(Details(None))}
           /> */
         <Text> {ReasonReact.string("Home screen key: ")} </Text> </View>
    </SafeAreaView>;
  },
};

[@bs.deriving abstract]
type jsProps = {
  navigation: string,
  params: string,
};

let render =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~navigation=jsProps->navigationGet, ~params=jsProps->paramsGet, [||])
  );
