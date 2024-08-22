# Context Free Grammar

## Syntax Symbols

### Terminal Symbols

1. the lowercase letters at the top of the alphabet
2. operator
3. punctuation mark
4. number
5. **bold string**

### Nonterminal Symbols

1. the uppercase letters at the top of the alphabet
2. Italic *name* with lowercase letters

from 《编译原理》, chapter 4.2.1

## remove left recursive

$$
A\to A\alpha|\beta\\
----------\\
\\
A\to\beta A'\\
A'\to\alpha A'|\epsilon
$$

$$
\begin{aligned}
&\text{nonterminal symbols}\ A_1,A_2,...,A_n:\\
&\text{for}\ i\ (1\to n):\\
&\ \ \ \ \text{for}\ j\ (1\to i-1):\\
&\ \ \ \ \ \ \ \ \text{replace}\ A_i\to A_j\gamma\\
&\ \ \ \ \ \ \ \ \text{with}\ A_i\to \delta_1\gamma|\delta_2\gamma|...|\delta_k\gamma,\\
&\ \ \ \ \ \ \ \ \text{where}\ A_j\to \delta_1|\delta_2|...|\delta_k\\
&\ \ \ \ \text{remove-lr}(A_i)
\end{aligned}
$$