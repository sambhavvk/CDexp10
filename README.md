### Aim:generate intermediate code for an arithmetic expression using DAG (Directed Acyclic Graph) technique

## Algorithim:
Read an arithmetic expression from the user.
Find all the operators in the expression and store their positions and types (i.e., +, -, *, /, :, (, and )) in an array of structures.
For each operator, generate the intermediate code for the sub-expression to its left and right using temporary variables (t1, t2, t3, etc.), and replace the sub-expression with the temporary variable in the original expression.
Print the intermediate code generated for each sub-expression.
Repeat steps 3 and 4 for all operators in the expression, until the whole expression is reduced to a single variable.
Print the final assignment statement for the result variable.
