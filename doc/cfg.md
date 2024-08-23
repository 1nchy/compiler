# Context Free Grammar

## Expression

- original version

$$
\begin{aligned}
E \to& T+E | T-E | T \\
T \to& U*T | U/T | U \\
U \to& -F | F \\
F \to& (E) \\
|& \text{INDENTIFIER} \\
|& \text{INTEGER} \\
|& \text{FLOAT} \\
\end{aligned}
$$

- LL1 version:

$$
\begin{aligned}
E \to& TE' \\
E' \to& +TE' | -TE' | \epsilon \\
T \to& UT' \\
T' \to& *UT' | /UT' | \epsilon \\
U \to& -F | F \\
F \to& (E) \\
|& \text{INDENTIFIER} \\
|& \text{INTEGER} \\
|& \text{FLOAT} \\
\end{aligned}
$$