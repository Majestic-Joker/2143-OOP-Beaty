## P03B - BolNiverse Fight Club
### Joshua Beaty, Alexander Ryan, Aodhan Shaw, Blake Guana
### Description:
Using starter code from Dr. Griffin, built a pretty cool battle simulator that generates a team of attackers and defenders based on either a user prompt or command line file input. It will update the console every step and display battle results at the end.

### Files

|   #   | File                          | Description                                                       |
| :---: | ----------------------------- | ----------------------------------------------------------------- |
|   1   | [main.cpp](./main.cpp)        | Main driver of the program.                                       |
|   2   | [fighter.hpp](./fighter.hpp)  | Implements basefighter class and all children of it.              |
|   3   | [weapon.hpp](./weapon.hpp)    | Implements weapon class and all children of it.                   |
|   4   | [dice.hpp](./dice.hpp)        | Implements dice class.                                            |
|   5   | [helpers.hpp](./helpers.hpp)  | Implements a few methods that don't really belong anywhere else.  |
|   6   | [input](./input)              | Sample input, this is what the program is expecting for commandLineProcessing |
|   7   | [output](./output)            | Output of battle statistics.                                      |


### Instructions

- Your Input file should be structured in the same way as the example [input](./input) file.
- In main.cpp, make sure you have set commandLineProcessing to true on line 26
- When running main from the console, you can access your input using the < operator on the command line.

### Example Command

- main < input
