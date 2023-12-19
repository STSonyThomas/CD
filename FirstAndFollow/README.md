# First and Follow Algorithm
1. Take input of the number of productions.
2. Input the productions as strings.
3. Define FIRST:
    1. If the character whose FIRST is required is a terminal then the FIRST of that symbol is the symbol itself.
    2. If the charater whose FIRST is required is a non terminal then the FIRST of the required symbol will be: 
        1. A terminal if the first character encountered in the production of the non terminal is a terminal.
        2. The FIRST of the very first non-epsilon non terminal encountered when the production is expanded.
    3. If the FIRST of the very first non-terminal has an epsilon in it then the FIRST of the very next non-terminal or the very next terminal is also added to the the FIRST of the required symbol.
4. Define FOLLOW:
    1. The follow of a required symbol will be "$" if the symbol is the starting symbol.
    2. The follow of a required symbol will be the FIRST of the very first non-terminal enocountered after the required symbol, or,
        1. The very first terminal encountered.
    3. If the very first non-terminal encountered has an epsilon in its FIRST or is an epsilon then the FOLLOW of the LEFT SIDE of the production is also there in the FOLLOW of the requried symbol.
5. Calculate the FIRST and FOLLOW.
6. End of program.