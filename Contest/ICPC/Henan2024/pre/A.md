直角三角形斜边长为 $n$，求一条边为正整数时，另一条直角边的期望/n的值。

$$
\sum\limits_{i=1}^{n-1}\dfrac{\sqrt{n^2-i^2}}{n(n-1)}
$$

$$
\begin{align*}
&\lim\limits_{n \to \infty} \sum\limits_{i=1}^{n-1}\dfrac{\sqrt{n^2-i^2}}{n(n-1)} \\
&=\lim\limits_{n \to \infty} \sum\limits_{i=1}^{n}\dfrac{\sqrt{n^2-i^2}}{n^2} \dfrac{n}{n-1}\\
&=\lim\limits_{n \to \infty} \sum\limits_{i=1}^{n}\dfrac{\sqrt{n^2-i^2}}{n^2}\\
&=\lim\limits_{n \to \infty} \sum\limits_{i=1}^{n}\sqrt{1-(\dfrac{i}{n})^2}\cdot \dfrac{1}{n}\\
&=\int_{0}^{1}\sqrt{1-x^2}dx\\
&=\dfrac{\pi}{4}
\end{align*}
$$

