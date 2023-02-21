## 7-1 签到 (5 分)

输入两个数字 a, b. 如果 a<b 输出 a b，否则输出 b a

```c
#include <stdio.h>

int main() {
    int a, b, t;
    scanf("%d%d", &a, &b);
    if (a > b)
        printf("%d %d", b, a);
    else
        printf("%d %d", a, b);
    return 0;
}
```

## 7-2 大小写字母转换 (5 分)

首先输入整个字符串，依次遍历每个字符。

大小写字母转换，利用ascall码。例如：'b'='B'-'A'+'a'，'B'='b'-'a'+'A'

```c
#include <stdio.h>

int main() {
    char s[105];
    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; i++)
        if ('a' <= s[i] && s[i] <= 'z')
            s[i] += -'a' + 'A';
        else if ('A' <= s[i] && s[i] <= 'Z')
            s[i] += -'A' + 'a';
    printf("%s", s);
    return 0;
}
```

## 7-3 方阵平移 (10 分)

先考虑一个一维数组的平移 

| 1    | 2    | 3    |
| ---- | ---- | ---- |

向右移两个单位

|      |      | 1    | 2    | 3    |
| ---- | ---- | ---- | ---- | ---- |

把超出的部分补充到前面

| 2    | 3    | 1    |
| ---- | ---- | ---- |

每个数字的移动过程

1：0—>0+2=2—>2%3=2

2：1—>1+2=3—>3%3=0

3：2—>2+2=4—>4%3=1

所以可以推出平移公式

$a[j]\to b[(j+k)\mod n]$，a是原数组，b是平移后的数组

同时，我们的行操作和列操作是两个互不冲突的过程，所以可以同时进行操作

$a[i][j]\to b[(i + l)\mod n][(j + k)\mod n]$

```c
#include <stdio.h>

int main() {
    int n, k, l;
    scanf("%d %d %d", &n, &k, &l);
    int a[n][n], b[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[(i + l) % n][(j + k) % n] = a[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d", b[i][j]);
        printf("\n");
    }
    return 0;
}
```

另外，本题有一个不用额外数组，直接输出的思路，这里就不再描述了，可以自己动脑考虑考虑。

## 7-4 今年是兔年 (10 分)

很明显，这题也是用到了取余运算，很全面地考察语法掌握。

- 首先凭自己所掌握的去计算下面这四个题：

  - 5 % 3 = 

  - 5 % -3 = 

  - -5 % 3 = 

  - -5 % -3 = 

  然后自己代码实现一下，看看是不是和自己想的一样。这里直接展示答案，前两个是2，后两个是-2

  可以发现，计算结果的符号与被模数的符号保持一致。

- 针对于中文汉字的保存形式，哪个是正确的？

  - `char s[4][8] = {"鼠"， "牛"， "虎", "兔"} `

  - `char s[4] = "鼠牛虎兔"`

  - `char s[8] = {'鼠'， '牛'， '虎', '兔'}`

    正确的只有前两个，并且第二个不能使用索引获得单独汉字

所以，这题首先使用字符数组存储汉字，然后注意负数的模运算，这两点搞清楚，就能通过了。

```c
#include <stdio.h>

int main() {
    int y;
    char s[12][8] = {"鼠", "牛", "虎", "兔", "龙", "蛇", "马", "羊", "猴", "鸡", "狗", "猪"};
    scanf("%d", &y);
    int ans = (y - 2020) % 12;
    if (ans < 0)
        ans = (ans + 12) % 12;
    printf("%d是%s年", y, s[ans]);
    return 0;
    
}
```

## 7-5 输出字符串 (10 分)

这个题可以使用结构体，记录字符串和输入顺序，然后排序。

但是也可以用更简单的写法，每次输入都计算一下长度，如果是第一个输入的，或者输入的长度**大于等于**前面的最长的，那么分别保存其长度和内容。这里**等于**，就能完成`长度相同则输出出现较晚的那一个`这个条件。

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, l;
    char s[105], ans[105];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        gets(s);
        int len = strlen(s);
        if (i == 0 || len >= l) {
            l = len;
            strcpy(ans, s);
        }
    }
    printf("%s", ans);
    return 0;
}
```

## 7-6 计算阶乘和 (20 分)

看起来非常简单的一个题，过半的人都尝试过，但都没有拿到满分。

因为这题有个精心设计的测试点

| n=12    | 522956313           |
| ------- | ------------------- |
| INT_MAX | 2147483647          |
| n=13    | 6749977113          |
| n=20    | 2561327494111820313 |
| LL_MAX  | 9223372036854775807 |

当 n＞12时，使用 `int` 一定会遇到数据溢出的错误

```c
#include <stdio.h>

int main() {
    int n;
    long long sum = 0, mul = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++, mul *= i)
        sum += mul;
    printf("%lld", sum);
    return 0;
}
```

## 7-7 IP地址转换 (20 分)

先整个输入字符串，然后8个二进制数一组，分别转成十进制数，并输出

```c
#include <stdio.h>
int main() {
    char s[40];
    scanf("%s", s);
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 8; j++)
            sum += (s[i * 8 + j] - 48) << (7 - j);
        printf("%d", sum);
        if (i != 3)
            printf(".");
    }
    return 0;
}
```

## 7-8 验证“哥德巴赫猜想”  (20 分)

判断素数的板子背熟

从第一个质数开始到n/2的范围查找符合条件的答案

```c
#include <stdio.h>

int isPrime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return x != 0 && x != 1;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n / 2; i++) {
        if (isPrime(i) && isPrime(n - i)) {
            printf("%d = %d + %d\n", n, i, n - i);
            break;
        }
    }
    return 0;
}
```

## 7-9 黑洞数 (20 分)

先通过模运算获取每一位数字，再给数字排序，重新组成最大数和最小数，做差判断是否等于495，如果不等于，继续执行相同操作。

```c
#include <stdio.h>

int main() {
    int n, i = 1;
    scanf("%d", &n);
    do {
        int a, b, c, p, q, t;
        a = n % 10;
        b = n / 10 % 10;
        c = n / 100 % 10;
        if (a > b)
            t = a, a = b, b = t;
        if (a > c)
            t = a, a = c, c = t;
        if (b > c)
            t = b, b = c, c = t;
        p = c * 100 + b * 10 + a;
        q = a * 100 + b * 10 + c;
        printf("%d: %d - %d = %d\n", i++, p, q, p - q);
        n = p - q;
    } while (n != 495);
}
```

**截止到第9题，都是语法的考察和一些简单的模板，是一定要掌握的题。**

------

## 7-10 纪念品领取  (30 分)

这是一道思维题。

我们假设有一排无限长的座位，n个人分别坐在 1-n 的位置

对于第 i 次抽签，都会让被抽到的人坐到最后一个人的后面

```txt
1 2 3 4 5 6 7 8
第1次抽签
_ 2 3 4 5 6 7 8 1
第2次抽签
_ 2 _ 4 5 6 7 8 1 3
第3次抽签
_ 2 _ 4 _ 6 7 8 1 3 5
第4次抽签
_ 2 _ 4 _ 6 _ 8 1 3 5 7
前5个
2 4 6 8 1
排序
1 2 4 6 8
```

观察样例，可以发现，对于第 i 次抽签的人，位置会被更新为 n+i

我们需要这样一个数据结构，保存每个人的id和每个人的位置，并且可以通过索引`[i]`获取第 i 人的信息

很明显可以使用这样一个结构体数组

```cpp
struct Node {
	int id, position;
};
Node A[n + 1];
for (int i = 1; i <= n; i++)
	A[i].id = i, A[i].position = i;
```

然后先按照 position 对结构体进行升序排序，再取前 5 个对 id 进行升序排序，输出 id 就可以了

c++内置数据结构`pair<T, T>` ，可以不用另外声明结构体了。

```cpp
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e5 + 5;
int main() {
    pii arr[N];
    int ans[6]{0};
    int n, m, i;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        arr[i].first = i, arr[i].second = i;
    for (int j = 1; j <= m; j++) {
        cin >> i;
        arr[i].second = n + j;
    }
    sort(arr + 1, arr + n + 1, [](const pii &a, const pii &b) { return a.second < b.second; });
    for (int i = 1; i <= 5; i++)
        ans[i] = arr[i].first;
    sort(ans + 1, ans + 6);
    for (int i = 1; i <= 5; i++)
        cout << ans[i] << " \n"[i == 5];
    return 0;
}
```

## 7-11 点球大战 (30 分)

点球大战结束的条件（出自题目原文）：

**而若在罚完某一球后（无论是哪队罚的），当前双方比分已经使得无论之后的罚球结果如何都不会影响比赛的结果，则此时比赛结束**

那么可以这么判断，在某一队罚完球后，如果

**A队的进球数 + A队的剩余场数 < B队的进球数** 或 **B队的进球数 + B队的剩余场数 < A队的进球数**

此时进球少的一方即使后面全赢，对手全输，也无法扳平局面，那么比赛结束

样例中，**1101011100**（2022世界杯决赛战绩）

在第8个罚球后，A队进球2个，B队进球4个，A队还剩1场，2+1<4，所以比赛结束于第八场。

```c
#include <stdio.h>

int main() {
    char s[15];
    scanf("%s", s);
    int res[2] = {5, 5}, score[2] = {0, 0};
    for (int i = 0; i < 10; i++) {
        int team = i % 2;
        res[team]--;
        score[team] += s[i] - '0';
        if (score[0] + res[0] < score[1] || score[1] + res[1] < score[0]) {
            printf("%d", i + 1);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
```

## 7-12 RMQ (30 分)

初看这个题，像是很简单的用for循环就能写的题。于是快速写出如下代码。

```c
#include <stdio.h>
#define N 100005

int n, p, q;
int arr[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", arr + i);
    scanf("%d", &p);
    for (int a, b, v; p--;) {
        scanf("%d %d %d", &a, &b, &v);
        for (int j = a; j <= b; j++)
            arr[j] += v;
    }
    scanf("%d", &q);
    for (int t; q--;) {
        scanf("%d", &t);
        printf("%d\n", arr[t]);
    }
    return 0;
}
```

然后提交发现第三个测试点显示**运行超时**

考虑到 1≤a≤b≤n   p≤100000

这个循环最多是 $10^5 \times 10^5$ 的层数，理论上 $10^8$ 以上的数量级就会超时

我们考虑这样一个数组

$a[i] = {0, 1, 2, 3, 4}$

令 $b[i] = a[i] - a[i-1]$

则 $a[i] = a[i-1] + b[i]$

$b[i] = \{0, 1, 1, 1, 1\}$

我们对数组 $a$ 进行操作，把区间 $[2, 3]$ 的元素 $+x$

$a[i] = \{0,\ 1,\ 2+x,\ 3+x,\ 4\}$

$b[i] = \{0,\ 1,\ 1+x,\ 1,\ 1-x\}$

比较一下 $b$ 数组的变化，$b[2]+x,\ b[4]-x$

事实上，对于 $a$ 数组任意区间 $[l, r]$ 的修改，都可以表示为b数组的两点修改，即 $b[l]+x,\ b[r+1]-x$

并且，这种修改是可叠加的

即先后对 $a$ 数组任意区间 $[l_1, r_1]$ $[l_2,r_2]$ 的修改

等价于 $b[l_1]+x,\ b[r_1+1]-x,\ b[l_2]+y,\ b[r_2+1]-y$

这种思想被称为**差分**

我们尝试使用这个方法

数组 $d[i]$ 表示 $i$ 处增量的差分，初始时增量为0

所有修改结束后通过差分结算增量

```c
#include <stdio.h>
#define N 100005
int arr[N], d[N];
int n, p, q;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", arr + i);
    scanf("%d", &p);
    for (int i = 0, a, b, v; i < p; i++) {
        scanf("%d %d %d", &a, &b, &v);
        d[a] += v;
        d[b + 1] -= v;
    }
    for (int i = 2; i <= n; i++)
        d[i] += d[i - 1];
    scanf("%d", &q);
    for (int t; q--;) {
        scanf("%d", &t);
        printf("%d\n", arr[t] + d[t]);
    }
    return 0;
}
```

## 7-13 取石子 ，但是作弊 (50 分)

博弈论的Nim游戏结论：若 $n$ 堆石子的数量异或和非 $0$ 时，则先手必胜，否则先手必败

原理这里就不说了，比较难的内容，建议基础扎实再学习。

所以，我们需要从第一堆移动k个石子到其他堆，使得每堆石子的数量异或和为0

```c
#include <stdio.h>
int main() {
    int n, s = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        s ^= a[i];
    }
    if (s == 0) {
        printf("0");
        return 0;
    }
    for (int i = 1; i < a[0]; i++)
        for (int j = 1; j < n; j++) {
            int x = a[0] - i, y = a[j] + i;
            int t = s ^ a[0] ^ a[j] ^ x ^ y;
            if (t == 0) {
                printf("%d", i);
                return 0;
            }
        }
    printf("-1");
    return 0;
}
```
