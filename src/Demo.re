/* VSCode Recommended Editor by Fbook */
/* "editor.formatOnSave": true */
/* $ code ll-03-13-18 */
Js.log("Hello, BuckleScript and Reason!");

/* SECTION 1: START */
let add = (x, y) => x + y;

/* let doesntwork = add(3, "foobar") */
let sum = add(3, 4);

/* SECTION 1: END */
/* SECTION 2: START */
/* Tuples */
let ageAndName: (int, string) = (24, "Lil' Reason");

/* a tuple type alias */
type coord3d = (float, float, float);

let my3dCoordinates: coord3d = (20.0, 30.5, 100.0);

let (_, y, _) = my3dCoordinates; /* now you've retrieved y */

/* SECTION 2: END */
/* SECTION 3: START */
/* Type Aliases */
type scoreType = int;

let x: scoreType = 10;

/* SECTION 3: END */
/* SECTION 4: START */
/* Function */
let greet = name => "Hello " ++ name;

/* SECTION 4: END */
/* SECTION 5: START */
/* Type Arguments */
type intCoordinates = (int, int, int);

type floatCoordinates = (float, float, float);

let buddy: intCoordinates = (10, 20, 20);

type coordinates('a) = ('a, 'a, 'a);

/* apply the coordinates "type function" and return the type (int, int, int) */
type intCoordinatesAlias = coordinates(int);

let buddy: intCoordinatesAlias = (10, 20, 20);

/* or, more commonly, write it inline */
let buddy: coordinates(float) = (10.5, 20.5, 20.5);

/* SECTION 5: END */
/* SECTION 6: START */
/* Destructuring */
let somePerson = {name: "Guy", age: 30};

let {name, age} = somePerson;

/* SECTION 6: END */
/* SECTION 7: START */
/* Pattern Matching */
type schoolPerson =
  | Teacher
  | Director
  | Student(string);

let greeting = stranger =>
  switch (stranger) {
  | Teacher => "HEY Prof!"
  | Director => "Hello Director person"
  | Student("foo") => "Why hello there Mr Bar"
  | Student(otherName) => "I do not know you" ++ otherName
  };

type payload =
  | BadResult(int)
  | GoodResult(string)
  | NoResult;

let data = GoodResult("Product shipped!");

let message =
  switch (data) {
  | GoodResult(theMessage) => "Success! " ++ theMessage
  | BadResult(errorCode) =>
    "Something's wrong. The error code is: " ++ string_of_int(errorCode)
  | NoResult => "TODO, COMMENT ME OUT!!!"
  };

type person = {
  name: string,
  age: int,
};

/* let myList = [1,2,3]; TODO UNCOMMENT */
let myList = ["foo", "bar"];

switch (myList) {
| [] => print_endline("Empty list")
| [a, ...theRest] =>
  print_endline("list with the head value " ++ a ++ "plus the rest")
};

let message = "Hello";

let reply =
  switch (message) {
  | "Reason's pretty cool" => "Yep"
  | "good night" => "See ya!"
  | "hello"
  | "hi"
  | "heya"
  | "hey" => "hello to you too!"
  | _ => "Nice to meet you!"
  };

let message =
  switch (data) {
  | GoodResult(theMessage) => "Success! " ++ theMessage
  | BadResult(0 | 1 | 5) => "Something's wrong. It's a server side problem."
  | BadResult(errorCode) =>
    "Unknown error occurred. Code: " ++ string_of_int(errorCode)
  | NoResult => "Things look fine"
  };

let isServerError = error => error == 500;

let message =
  switch (data) {
  | GoodResult(theMessage) => 1
  | BadResult(errorCode) when isServerError(errorCode) => 2
  | BadResult(errorCode) => 2
  | NoResult => 3
  };

let theItem = "needle";

let myItems = ["a", "b", "c"];

switch (List.find(i => i === theItem, myItems)) {
| item => print_endline(item)
| exception Not_found => print_endline("No such item found!")
};

let possiblyNullValue1 = None;

let possiblyNullValue2: option(string) = Some("Hello@");

switch (possiblyNullValue2) {
| None => print_endline("Nothing to see here.")
| Some(message) => print_endline(message)
};

/* SECTION 7: END */
/* SECTION 8: START */
Js.log("this is reason");

%bs.raw
{|
console.log('here is some javascript for you');
|};

Js.log("this is reason");

let x = [%bs.raw {| 'here is a string from javascript' |}];

Js.log(x ++ " back in reason land"); /* ++ is the operator for string concat */
/* SECTION *: END */