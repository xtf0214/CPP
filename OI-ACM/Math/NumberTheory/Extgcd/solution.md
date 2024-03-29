在RSA密码体系中, 欧几里得算法是加密或解密运算的重要组成部分。它的基本运算过程就是解 $ax\equiv 1\pmod n$ 这种方程。整个解的过程是这样的，我们用一个例子来说明。

当a = 1001 ，n = 3837时
方程为 x * 1001 = 1 (mod 3837)
求解过程：
3837 = 3 * 1001 + 834
1001 = 1 * 834 + 167
834 = 4 * 167 + 166
167 = 1 * 166 + 1

所以
1 = 167 + (–1) * 166
= 167 - (834 - 4 * 167)
= -1 * 834 + 5 * 167
= 5 *(1001 - 834) – 834
= 5 * 1001 + (-6) * 834
= 5 * 1001 - 6 * (3837 -3 * 1001)
= -6 * 3837 + 23 * 1001

然后对等式两端同时除以模3837得
23 * 1001 = 1 (mod 3837)
于是 x = 23
现在给出a和n，你能不能在最短的时间内解出这个方程呢？

### 输入

输入包括多组测试数据。每组测试数据对应输入的一行，每行包括两个整数a和n。1<a,n<2^31(用long可以存下)
当a=n=0时输入结束，这组数据不包括在需要计算的数据中。

### 输出

对应每组输入数据，输出最小的满足题意的解x。

### 样例输入

1001 3837
136468984 134548555
0 0
### 样例输出

23
112206854

### 提示

1. 本题用穷举是不可能做出来的
2. 结果必须是正数

### sol.

$1001x\equiv 1 \pmod {3837}$

$1001x-3837y=1$

| NO. | p     | q     | d     | A   | (x,y)  |
| --- | ----- | ----- | ----- | --- | ------ |
| 0   | 1001  | -3837 | 0     | 6   | (23,6) |
| 1   | -3837 | 1001  | -3    | 23  | (6,23) |
| 2   | 1001  | -834  | -1    | 6   | (5,6)  |
| 3   | -834  | 167   | -4    | 5   | (1,5)  |
| 4   | 167   | -166  | -1    | 1   | (1,1)  |
| 5   | -166  | 1     | -166  | 1   | (0,1)  |
| 6   | 1     | 0     | infty | 0   | (1,0)  |
|     |       |       |       | 1   |        |


`A[i] = A[i + 2] - A[i + 1] * d[i];`

`p[i] * A[i] + q[i] * A[i + 1] = 1`