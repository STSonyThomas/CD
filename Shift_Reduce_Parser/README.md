# Shift Reduce Parser

Here one particular grammar is considered for the scope of this program we will be considering 
```
 E->E+E 
 E->E*E
 E->(E)
 E->id
```

We have to define the Shift and reduce actions for the above grammar in C language

# Algorithm

1. Define variables for the stack, input, actions.
2. Take user input for a string;
3. Take the length of the string using the strlen function.
4. Traverse the entire string one character at a time.
5. Each time a character is input to the stack the shift action takes place on the symbol.
6. If the symbol being input is **id** then the stack has to update two positions to accomodate the **id** symbol.
7. After each symbol is input to stack use a check function to check if the characters can be reduced.
8. If they can be reduced then perform the reduction to them in the stack and update positions.
9. Once the entire input string has been reduced the program is complete.
10. End.