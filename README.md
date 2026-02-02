# `calcic-tests`

*Written by @dabecart, 2026*

Testing units for the [calcic](https://github.com/dabecart/calcic) compiler.

These tests are grouped around different C concepts which are to be implemented sequentially. Tests 
are all found inside the [tests](tests) folder. There are two folders for each test group, *valid* 
and *invalid*. As the name implies, the *invalid* tests are made to trigger compilation errors. The 
*valid* tests are expected to compile and must generate a return code specified at the top of the 
file containing the `main()` function.

## `constant_folding`

Check the expressions evaluated during compilation, for example, for the initial value of global 
storage variables. 

## `const`

This is a type qualifier. There is a distinction between const types and const pointers that has to 
be taken into account.
