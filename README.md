# SymbolCombinationFinder
finds combination of '+', '-', '*' and '/' between given numbers to get a given result

(work in progress)

so far done:
  1. functions to get and store multiple inputs from user
  2. function to generate '+' '-' '*' '/' for given inputs
  3. function to solve arithmetic expression
  4. use and display of arithmetic solving function
  
  
to do:
  1. make function to generate all possible combination of brackets for given numbers
  2. make wrapper function for arithmetic solving function to incorporate brackets
  3. add logic to solve and store possible result(s) if not closest possible result
  
Goal isn't targetted towards speed at the moment, thus programme has only been tested for small input sizes.

Result from current iteration of programme for given input "4 2 6 7":
4 + 2 + 6 + 7 = 19

4 + 2 + 6 - 7 = 5

4 + 2 + 6 * 7 = 48

4 + 2 + 6 / 7 = 6.85714

4 + 2 - 6 + 7 = 7

4 + 2 - 6 - 7 = -7

4 + 2 - 6 * 7 = -36

4 + 2 - 6 / 7 = 5.14286

4 + 2 * 6 + 7 = 23

4 + 2 * 6 - 7 = 9

4 + 2 * 6 * 7 = 88

4 + 2 * 6 / 7 = 5.71429

4 + 2 / 6 + 7 = 11.3333

4 + 2 / 6 - 7 = -2.66667

4 + 2 / 6 * 7 = 6.33333

4 + 2 / 6 / 7 = 4.04762

4 - 2 + 6 + 7 = 15

4 - 2 + 6 - 7 = 1

4 - 2 + 6 * 7 = 44

4 - 2 + 6 / 7 = 2.85714

4 - 2 - 6 + 7 = 3

4 - 2 - 6 - 7 = -11

4 - 2 - 6 * 7 = -40

4 - 2 - 6 / 7 = 1.14286

4 - 2 * 6 + 7 = -1

4 - 2 * 6 - 7 = -15

4 - 2 * 6 * 7 = -80

4 - 2 * 6 / 7 = 2.28571

4 - 2 / 6 + 7 = 10.6667

4 - 2 / 6 - 7 = -3.33333

4 - 2 / 6 * 7 = 1.66667

4 - 2 / 6 / 7 = 3.95238

4 * 2 + 6 + 7 = 21

4 * 2 + 6 - 7 = 7

4 * 2 + 6 * 7 = 50

4 * 2 + 6 / 7 = 8.85714

4 * 2 - 6 + 7 = 9

4 * 2 - 6 - 7 = -5

4 * 2 - 6 * 7 = -34

4 * 2 - 6 / 7 = 7.14286

4 * 2 * 6 + 7 = 55

4 * 2 * 6 - 7 = 41

4 * 2 * 6 * 7 = 336

4 * 2 * 6 / 7 = 6.85714

4 * 2 / 6 + 7 = 8.33333

4 * 2 / 6 - 7 = -5.66667

4 * 2 / 6 * 7 = 9.33333

4 * 2 / 6 / 7 = 0.190476

4 / 2 + 6 + 7 = 15

4 / 2 + 6 - 7 = 1

4 / 2 + 6 * 7 = 44

4 / 2 + 6 / 7 = 2.85714

4 / 2 - 6 + 7 = 3

4 / 2 - 6 - 7 = -11

4 / 2 - 6 * 7 = -40

4 / 2 - 6 / 7 = 1.14286

4 / 2 * 6 + 7 = 19

4 / 2 * 6 - 7 = 5

4 / 2 * 6 * 7 = 84

4 / 2 * 6 / 7 = 1.71429

4 / 2 / 6 + 7 = 7.33333

4 / 2 / 6 - 7 = -6.66667

4 / 2 / 6 * 7 = 2.33333

4 / 2 / 6 / 7 = 0.047619
