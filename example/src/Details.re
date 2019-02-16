/* open BsReactNative;

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

   type params = int;

   let make =
       (~navigation: NavigationConfig.Navigation.t, ~params: params, _children) => {
     ...component,
     render: _self => {
       Js.log(params);
       let getRandStr = string_of_int(Random.int(1123));

       let test = navigation.push(`Home);

       let _title = "Go to details screen with params" ++ getRandStr;
       Js.log(navigation);

       <SafeAreaView>
         <View style=Styles.container>
           <Text> {ReasonReact.string("Params : ")} </Text>
         </View>
       </SafeAreaView>;
     },
   }; */
