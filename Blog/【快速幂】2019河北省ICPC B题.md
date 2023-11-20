> 题目链接：[https://ac.nowcoder.com/acm/contest/903/B](https://ac.nowcoder.com/acm/contest/903/B)

## 矩阵快速幂

令

$$
A=\begin{bmatrix}
  q&1\\
  0&1
\end{bmatrix}
$$

$$
A^2=A\cdot A=\begin{bmatrix}
  q^2&q+1\\
  0&1
\end{bmatrix}
$$

$$
...
$$

$$
A^n=\begin{bmatrix}
  q^n&q^{n-1}+...+q+1\\
  0&1
\end{bmatrix}
$$

使用快速幂优化：

$$
n=\sum\limits_{i=0}^{\lfloor\log n\rfloor} c_i\cdot 2^i
\ (c_i\in \{0,1\})
$$

$$
A^n=A^{\sum\limits_{i=0}^{\lfloor\log n\rfloor} c_i\cdot 2^i}=\prod_{i=0}^{\lfloor\log n\rfloor}A^{c_i\cdot 2^i}
$$

则：

$$
\sum\limits_{i=1}^{n}q^i=A^n[0][0]+A^n[0][1]-1
$$

## 快速幂分治

令

$$
f(n)=\sum\limits_{i=1}^{n}q^i
$$

则
$$
f(n)=\begin{cases}
(1+q^{\lfloor \frac{n}{2} \rfloor})\cdot f(\lfloor \frac{n}{2} \rfloor)&\text{ if } x \text{ is even}\\
(1+q^{\lfloor \frac{n}{2} \rfloor})\cdot f(\lfloor \frac{n}{2} \rfloor)+q^n&\text{ if } x \text{ is odd}\\
\end{cases}
$$
