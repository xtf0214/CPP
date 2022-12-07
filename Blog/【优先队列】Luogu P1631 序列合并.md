# 【优先队列】Luogu P1631 序列合并

> ### 题目描述
>
> 有两个长度都是N的序列A和B，在A和B中各取一个数相加可以得到 $N^2$ 个和，求这 $N^2$ 个和中最小的N个。
>
> ### 输入格式
>
> 第一行一个正整数N；
>
> 第二行N个整数 $A_i$ , 满足 $A_i\le A_{i+1}$ 且 $A_i\le 10^9$ ;
>
> 第三行N个整数 $B_i$ , 满足 $B_i\le B_{i+1}$ 且 $B_i\le 10^9$ .
>
> 【数据规模】
>
> 对于50%的数据中，满足1<=N<=1000；
>
> 对于100%的数据中，满足1<=N<=100000。

首先枚举一下 $n^2$ 个和

| $a_0+b_0$     | $a_0+b_1$     | $\cdots$ | $a_0+b_{n-1}$     |
| ------------- | ------------- | -------- | ----------------- |
| $a_1+b_0$     | $a_1+b_1$     | $\cdots$ | $a_1+b_{n-1}$     |
| $\vdots$      | $\vdots$      | $\ddots$ | $\vdots$          |
| $a_{n-1}+b_0$ | $a_{n-1}+b_1$ | $\cdots$ | $a_{n-1}+b_{n-1}$ |

可以发现，在同行或同列中，值是单调的。

首先把行看作一个单调数列，从 $n$ 个数列中取每个的最小值，总共 $n$ 个最小值，再选择最小的最小值，这是第一小，重复以上操作 $n$ 次即可求得最小的 $n$ 个。其中 $n$ 个最小值可以使用优先队列维护，优先队列覆盖每个数列的最小值，其堆顶就是这 $n$ 个最小值的最小值。

```cpp
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<deque<int>> c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i].push_back(a[i] + b[j]);
    priority_queue<pii, vector<pii>, greater<pii>> Qmin;
    for (int i = 0; i < n; i++)
        Qmin.push({c[i].front(), i});
    for (int i = 0; i < n; i++) {
        auto [val, src] = Qmin.top();
        Qmin.pop();
        c[src].pop_front();
        cout << val << " ";
        Qmin.push({c[src].front(), src});
    }
    return 0;
}	
```

预处理 $O(n^2)$ ，求解 $O(n\log n)$ ，总时间复杂度为 $O(n^2)$ ，对于题目最大数据范围 $10^5$ 会TLE。可以把预处理省略掉，保存每个数列的头元素下标，加入优先队列时临时计算。时间复杂度为 $O(n\log n)$ 。

```cpp
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), st(n); // st存每个数列的头元素下标
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    priority_queue<pii, vector<pii>, greater<pii>> Qmin;
    for (int i = 0; i < n; i++)
        Qmin.push({a[i] + b[st[i]++], i});
    for (int i = 0; i < n; i++) {
        auto [val, src] = Qmin.top();
        Qmin.pop();
        cout << val << " ";
        Qmin.push({a[src] + b[st[src]++], src});
    }
    return 0;
}	
```

