# ReCuRsIvE DeScEnT PaRsEr

A recursive descent parser first creates a predictive parse table using FIRST and FOLLOW. The rules for the same can be found at:
 1. At page numbers 224-225 in the textbook **Compilers Principles, Techniques, Tools (Alfred V. Aho, Monica S. Lam, Ravi Sethi)**.
 2. At [Kerala Notes](https://drive.google.com/file/d/1bXWFGvHKrlcyRN32jB0ua_DwzJXCx1Vw/view).


# Algorithm

1. Decide on a grammer for the Recursive Descent Parser( RDP).
2. The grammar I have used is from [GeeksforGeeks](https://www.geeksforgeeks.org/recursive-descent-parser/).


```
E –> T E’ 
E’ –> + T E’ | e 
T –> F T’ 
T’ –> * F T’ | e 
F –> ( E ) | id
```
3. Then define a function for each non-terminal state
4. Check the success and failure at each state.
5. If the entire entered language instance follows the grammar rules defined through the function then SUCCESS state will be returned 
6. Else FAILURE state will be returned.