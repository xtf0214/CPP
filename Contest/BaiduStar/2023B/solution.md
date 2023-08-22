## A 星际航行

### problem

三维空间内 $n$ 个点，每个点为 $(x_i,y_i,z_i)$

让这 $n$ 个点排在一条直线上，并且距离为 $1$ 。

即选择两个维度坐标重合，例如 $x_1=x_2=\ldots=x_n,y_1=y_2=\ldots=y_n$

剩下的那个维度满足相邻为 $1$ ，例如 $|z_i-z_{i-1}|=1,(i=2,3,\ldots,n)$

求所有点移动的曼哈顿距离之和的最小值。

### solution

计算每个维度的最小绝对偏差 $\min\limits_{a=x_1}^{x_n}\sum\limits_{i=1}^n |x_i-a|$ 和 $\min\limits_{a=x_1}^{x_n}\sum_{i=1}^{n}|x_i-a+i-1|$

我的思路：

设 $f(a)=\sum_{i=1}^n |x_i-a|, \min{x_i}\le a\le\max{x_i}$

$g(a)=\sum_{i=1}^{n}|x_i-a+i-1|, \min{x_i}\le a\le\max{x_i}$

可以发现这是一个单峰的先减后增函数，使用三分法求峰值对应的 $a$（最小值）

时间复杂度 $O(n\log n)$

预处理 $x$ 的前缀和，通过二分查找 $x_i<a$ 和 $x_i+i-1<a$ 的最后位置 p，利用前缀和 $O(1)$ 计算 $f(a)$ 和 $g(a)$ .

时间复杂度可以优化到 $O(\log n \log n)$

佬的思路：

$a$ 为 $x[]$ 的中位数时，$f(a)$ 和 $g(a)$ 取最小值。

## C 夏日漫步

根据题意建图，每个节点连接相邻的前后节点和后面第一个亮度相同的节点，然后跑一遍BFS。

## D 怪兽

根据题意列方程：

$\begin{cases}
x+y+z=p \\
n_1x+n_2y+n_3z=q
\end{cases}$

消元 $x$ 得： $(n_3-n_1)y+(n_3-n_2)z=q-n_1\cdot p$ 

令 $a=n_3-n_1, b=n_2-n_1, c=q-n_1\cdot p, d=\gcd(a,b)$ , 则 $ay+bz=c$

用扩展欧几里得算法求解一个特解 $(y_0,z_0)$ 

沿着直线移动可以获得所有非负整数解

$\begin{cases}
y=y_0+\dfrac{b}{d}t \\
z=z_0-\dfrac{a}{d}t \\
\end{cases}$

其中 $t\in\left[\lceil\dfrac{y_0-0}{-b/d}\rceil,\lfloor\dfrac{z_0-0}{a/d}\rfloor\right]$