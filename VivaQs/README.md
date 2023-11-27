
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