Quick Editorial

<spoiler summary="Problem A">

With a little bit of math, the answer is just $\displaystyle \left⌈\frac{|a-b|}{2c}\right⌉$

</spoiler>

<spoiler summary="Problem B">

For every room $i$ let's the define $x_i$ as the minimum room number such that we will be trapped with room $i$ if we go to room $x_i$.

We can then find that $\displaystyle x_i = d_i +  \left⌈\frac{s_i}{2}\right⌉$

Let $X$ be the minimum among all $x_i$ ($1 \leq i \leq n$)

The answer is then: $\max(1, X - 1)$.

</spoiler>

<spoiler summary="Problem C">

Define $p_x$ as the divider of $x$ such that $p_x > 1$, then the answer is $(p_x, x - p_x)$.

We can find $p_x$ with Sieve of Eratosthenes, note that if $x$ is a prime then there is no answer.

</spoiler>

<spoiler summary="Problem D">

Let $z$ be the LCM of $x$ and $y$, let's define $C_x$ and $C_y$ as the number of indexes that $x$ and $y$ will have such that there are no shared indexed between $x$ and $y$.

We can see that:

- $\displaystyle C_x = \left\lfloor \frac{n}{x} \right\rfloor - \left\lfloor \frac{n}{z} \right\rfloor$
- $\displaystyle C_y = \left\lfloor \frac{n}{y} \right\rfloor - \left\lfloor \frac{n}{z} \right\rfloor$

We can then put values of $n$, $n-1$, $\dots$, $n-C_x+1$ for $x$ indexes and $1$, $2$, $\dots$, $C_y$ for $y$ indexes.

Let $\displaystyle F(x) = \frac{x \times (x + 1)}{2}$

Then the answer is: $F(n) - F(n - C_x) - F(C_y)$

</spoiler>

<spoiler summary="Problem E">

Let us denote $A$ as the XOR of all the numbers and $X$ as the XOR of all the numbers of indexes where $S_i = 0$.

Let us define $f(l, r)$ as the XOR of all numbers in range $[l, r]$.

Then in the first operation, we will have that $X$ is updated to $X \oplus f(l, r)$.

In the second operation, if $g=0$ then we can output $X$ otherwise we output $A \oplus X$.

We can use prefix XOR to compute $f(l, r)$.

</spoiler>

<spoiler summary="Problem F">

For this types of problems, we can imagine a graph where there is an edge between node $u$ and node $a_u$.

Then there will be a number of components, inside of each component there will be exactly one loop.

We need to find the minimum cost node inside each loop so that we can put it in the last indexes of $p$.

There are obviously lots of answers, one of being is we can put all the nodes "outside" the loops first (we can use some sort of toposort for this), and then we can put the nodes inside the loops by carefully putting the minimum cost node in the last.

</spoiler>

<spoiler summary="Problem G">

Notice that if all the multiples of $a$ is very large (we can set the max boundary as $10^18$) then it will always be optimal to multiply all of it, but here it will be more optimal to find the smallest $i$ and largest $i$ such that $a_i > 0$.

If the multiples of $a$ is not large, then there will exist only a small numbers $i$ such that $a_i > 0$ (probably not going to be more than $100$ depending on the scenarios).

Let $S$ be the set of indices $i$ such that $a_i > 0$.

Let us define $F(l, r) =\displaystyle \Pi_{i=l}^{r} a_i - \sum{i=l}^{r} a_i$

We can then bruteforce all pair of indices in $S$, then we need to find $(l, r)$ using $S$ such that $F(l, r)$ is minimized.

We can use prefix sum / multiply for this.

</spoiler>