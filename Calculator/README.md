
Here's an example input:

```

2 + 3
4 - 1
5 + 2 - 3` 
```  

Let's step through how the program would work:

### Step 1: Input

Input: `2 + 3`

### Step 2: Lexical Analysis (Tokenization)

The lexical analyzer (lexer) breaks the input into tokens:

-   Token 1: INTEGER (value = 2)
-   Token 2: '+'
-   Token 3: INTEGER (value = 3)
-   Token 4: '\n' (newline)

### Step 3: Syntax Analysis (Parsing)

The parser processes the tokens and builds the parse tree:

```

 `expr
   |
   +
  / \
 2   3` 
```

### Step 4: Semantic Analysis

The semantic analysis computes the values of the expressions in the parse tree:

```

 `expr (value = 5)
   |
   +
  / \
 2   3` 
```

### Step 5: Output

The result of the expression is printed:

Copy code
```
5 
```
### Step 6: Repeat for the Next Line

Repeat the above steps for the next lines of the input:

### Input: `4 - 1`

#### Tokenization:

-   Token 1: INTEGER (value = 4)
-   Token 2: '-'
-   Token 3: INTEGER (value = 1)
-   Token 4: '\n' (newline)

#### Parsing:

```

 `expr
   |
   -
  / \
 4   1` 
```
#### Semantic Analysis:

```

 `expr (value = 3)
   |
   -
  / \
 4   1` 
```

#### Output:
```
3 
```
### Input: `5 + 2 - 3`

#### Tokenization:

-   Token 1: INTEGER (value = 5)
-   Token 2: '+'
-   Token 3: INTEGER (value = 2)
-   Token 4: '-'
-   Token 5: INTEGER (value = 3)
-   Token 6: '\n' (newline)

#### Parsing:
```
 `expr
    |
    -
   / \
  +   3
 / \
5   2` 
```

---
#### Semantic Analysis:

```

 `expr (value = 4)
    |
    -
   / \
  +   3
 / \
5   2` 
```
#### Output:

Copy code

`4` 

### Summary

The program reads expressions line by line, parses them, evaluates the expressions, and prints the results. The steps involve lexical analysis, syntax analysis, semantic analysis, and finally, output.