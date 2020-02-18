# CalcConv
CalcConv is a Command-Line Calculator with additional functionalities. This project was developed as part of my mini project for Object Oriented Programming Using C++.

## Description of Modules 

There are a total of 4 modules and each module will be described here. 

1. Basic Module
2. Quadratic Equation Solver 
3. Unit Converter 
4. Logging  

### Basic Module 

This module does the basic arithmetic operations - Addition, Subtraction, Multiplication and Division. Exception for division by zero is also implemented. 

### Quadratic Equation Solver 

This module solves Quadratic Equations. It gets the input from the users for the Quadratic Equation of the form $ax^2 + bx + c = 0$. Using the Quadratic Formula, it is also able to solve the case for complex roots. 

Quadratic Formula: 

$-b \pm \sqrt{b^2 - 4ac} \over 2a$

### Unit Converter 

Currently, this module converts only lengths. It coverts from one unit of measurement to other units of measurements. It takes the input from the user in a specified unit and lists its equivalent in all units available.

### Logging  

This is the module that logs the history of all calculations done by all other modules. It creates a text file called “Log.txt” once the program runs. Whatever calculations performed by the user is logged with timestamp as well. If any errors or invalid operations were encountered, they will also be recorded.


## Future Improvements
There were additional plans to improve this software. The following are the possible improvements: 

1. Addition of Trigonometric Functions 
2. Upgrading Basic module to a more calculator-like format
3. Drawing of quadratic graph shapes using terminal 
4. Support for more units in Unit Converter module
