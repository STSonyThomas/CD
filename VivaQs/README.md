
# Viva Questions Asked

  

### <u>Give Example of bottom up parser</u>
Operator Precedence Parser

  

---

## <u>Explain how first and follow are found</u>

  

<u>FIRST</u>

  

In formal language theory, the "First" set of a grammar is a set of terminals that can appear as the first symbol of a string derived from a nonterminal. The rules for finding the First set are as follows:

  

**For Terminals:**

  

The First set of a terminal is the terminal itself. For example, if 'a' is a terminal, then First(a) = {a}.

**For Non-terminals:**

  

For a nonterminal A, if A → X1X2...Xk is a production rule, then add the First set of X1 to the First set of A, except when X1 can derive the empty string ε. If X1 can derive ε, add the First set of X2 to the First set of A, and so on, until a symbol that does not derive ε is found.

**For Empty String (ε):**

  

If a string of symbols can derive the empty string (ε), then add ε to the First set of the nonterminal.

**For Productions with Alternatives:**

  

If a nonterminal has multiple production rules, each producing different alternatives, take the union of the First sets of all those alternatives.

The process is typically applied iteratively until no more additions can be made to any First set. It may require multiple passes over the grammar to compute the First sets accurately.

  

<u>Here's a more formal representation of the rules:</u>

  

If X is a terminal, then First(X) = {X}.

If X is a nonterminal, then:

First(X) = First(X1) ∪ First(X2) ∪ ... ∪ First(Xk) for each production rule X → X1X2...Xk.

If X1, X2, ..., Xk can derive ε, then include ε in First(X).

These rules are fundamental in the construction of predictive parsers and are used to predict the production rule to apply during parsing based on the first input symbol.

---

## <u>What are the different forms of intermediate code?</u>

Intermediate code is an abstraction that sits between the source code and the target code in a compiler. It is designed to facilitate the translation of high-level programming languages into machine code. There are various forms of intermediate code, and some common ones include:

```
t1 = a + b
t2 = c * d
e = t1 - t2

```
**Quadruples:**

- Quadruples are a form of intermediate code that uses four fields: operator, operand1, operand2, and result. It's a more detailed representation compared to TAC.

```
+, a, b, t1
*, c, d, t2
-, t1, t2, e

```

**Triples:**

- Triples intermediate code uses three fields: operator, operand1, and operand2. Unlike TAC, each triple represents a single operation rather than a sequence of operations.
<u>Example Triples:</u>
```
+, a, b
*, c, d
-, t1, t2
```

**DAG (Directed Acyclic Graph):**

- DAG is a graphical representation of intermediate code where common subexpressions are identified and shared. It is often used for optimization purposes.
<u>Example DAG:</u>
```
DAG:
     +
    / \
   a   b
```

**Syntax Trees:**

- Syntax trees are a hierarchical representation of the syntactic structure of the source code. They are not directly an intermediate code but can be converted into one.
<u>Example Syntax Tree:</u>
```
    +
   / \
  a   *
     / \
    c   d
```

**Abstract Syntax Trees (AST):**

- AST is a more abstract version of the syntax tree that omits certain details present in the syntax tree. It represents the abstract syntactic structure of the code.
<u>Example AST:</u>
```
  +
 / \
a   *
   / \
  c   d
```

---

## <u>What are the different phases of a compiler?</u>

1. <u>Lexical Analysis (Scanner):</u>

- **Input:** Source Code
- The first phase involves breaking the source code into tokens, which are the smallest units of meaning (keywords, identifiers, operators, etc.). This process is carried out by the lexical analyzer or scanner.
2. <u>Syntax Analysis (Parser):</u>

- **Input:** Stream of Tokens
- The parser analyzes the syntactic structure of the source code based on the sequence of tokens. It generates a hierarchical structure such as a syntax tree or abstract syntax tree (AST). This phase ensures that the source code adheres to the grammatical rules of the programming language.
3. <u>Semantic Analysis:</u>

- **Input:** Syntax Tree or AST
- Semantic analysis checks for semantic errors and enforces language-specific rules that cannot be expressed in the grammar. It also involves creating a symbol table to manage identifiers and their attributes.
4. <u>Intermediate Code Generation:</u>

- **Input:** Syntax Tree or AST
- The compiler generates an intermediate code representation that serves as an abstraction between the high-level source code and the target machine code. This intermediate code is designed to be independent of the source and target languages, facilitating optimization and code generation.
5. <u>Code Optimization:</u>

- **Input:** Intermediate Code
- The compiler performs various optimization techniques on the intermediate code to improve the efficiency of the generated machine code. Optimization may include constant folding, loop optimization, and dead code elimination.
6. <u>Code Generation:</u>

- **Input:**: Intermediate Code
- The compiler translates the optimized intermediate code into the target machine code. Code generation involves mapping the abstract operations in the intermediate code to the specific instructions of the target architecture.

---

## <u>What is the difference b/w a lexeme and token?<u>

A lexeme is the smallest unit in the source code that the compiler recognizes as a meaningful entity. A token is a pair consisting of a token name (category) and an optional attribute value. In simpler terms, a lexeme is a sequence of characters in the source code that matches the pattern for a token. A token is the combination of a token name and any associated value, representing a language construct recognized by the compiler.

---

## <u>What is handle pruning?</u>

- Handle pruning is a step in the context of bottom-up parsing techniques, particularly in LR parsing. LR parsing involves constructing a bottom-up parse tree for a given input string. A handle is a substring of the right side of a production rule that can be reduced to the nonterminal on the left side of the rule.

- Handle pruning refers to the process of identifying and replacing a handle with the corresponding nonterminal during the construction of the parse tree. This step occurs during the reduction phase of LR parsing. The reduction involves replacing a sequence of symbols on the top of the parsing stack with the nonterminal that represents them.

- In other words, handle pruning is the act of recognizing a valid substring in the input that matches a production rule and then reducing that substring to the nonterminal of the corresponding rule. This process continues until the entire input is reduced to the start symbol, indicating successful parsing.

- Handle pruning is a crucial part of LR parsing algorithms, such as LR(0), SLR(1), LR(1), and LALR(1), where the parser uses a state machine to shift symbols onto the stack and reduce them when a handle is identified. The ability to recognize handles efficiently is fundamental to constructing a correct parse tree for the given input.