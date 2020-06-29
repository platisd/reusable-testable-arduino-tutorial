# How to write testable C++ for Arduino ![Arduino CI]

How to write testable and reusable C++ for Arduino, following the
[Inversion of Control principle](https://en.wikipedia.org/wiki/Inversion_of_control).

<a href="https://youtu.be/jCLgqaXS6Gg"><img src="https://i.imgur.com/awxkHQV.png" width="500"></a>

[Arduino CI]: https://github.com/platisd/reusable-testable-arduino-tutorial/workflows/Arduino%20CI/badge.svg?branch=master

## What?

This is the repository for the material included in the
[How to write testable C++ for Arduino](https://youtu.be/jCLgqaXS6Gg) video tutorial.

The tutorial demonstrates how to design and refactor C++ according to the **Inversion of Control**
principle (IoC), using Arduino compatible code as an example. To follow along, it is advised you
`clone` the repository and open it in an code editor.

### Contents of interest
* Calculator [resources](sketches/calculator) and [test](test/ut/calculator_test.cpp)
* MagicCarController [sketch](sketches/MagicCarController/MagicCarController.ino)
* MagicCarControllerTestable [resources](sketches/MagicCarControllerTestable) and [test](test/ut/MagicCarController_test.cpp)

## Homework

During the tutorial, you are tasked to complete the following tasks so to get hands-on practice with
unit testing for Arduino:

1. Finish the tests for the [Calculator sketch](sketches/calculator/calculator.ino).
2. Finish the tests for the [MagicCarControllerTestable sketch](sketches/MagicCarControllerTestable/MagicCarControllerTestable.ino).

Once you are done, you can try evolving the code further and experimenting with the following stretch
tasks:

1. Write more unit tests to cover more edge cases.
2. Inject the [lightsPin](https://github.com/platisd/reusable-testable-arduino-tutorial/blob/master/sketches/MagicCarControllerTestable/MagicCarController.cpp#L11) instead of hard-coding it.
3. Decouple the [RestServer](https://github.com/platisd/reusable-testable-arduino-tutorial/blob/master/sketches/MagicCarControllerTestable/RestServer.h) interface further from the ESP32 `WebServer` implementation and refactor the code as well as the tests accordingly.
4. Think of a better way to return an Arduino `String` in a platform-agnostic way.

### Solutions

The solutions can be found in the [solutions](https://github.com/platisd/reusable-testable-arduino-tutorial/tree/solutions) branch.

#### Shared solutions

Do you have a solution that you want to share with us? Then fork this repository, push your solution to it
and then let me know by opening an issue. I will add a link to your repo in this `README` file.
