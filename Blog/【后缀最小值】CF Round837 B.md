> 题目链接：[B. Hossam and Friends](https://codeforces.com/contest/1771/problem/B)
>
> ### 题目描述
>
> 给定 $m$ 个数对，对于 $1−n$ 的所有连续子序列中，任意一个数对都不能出现，这样的连续序列 $[a,b]$ 定义为好的序列，求这样的序列的数量。

我们考虑枚举左端点，计算右端点的最大值，其长度就是以这个左端点开始的序列对答案的贡献。

我们先用 $s$ 数组表示 $i$ 为左端点的第一个不能跨越的右端点。在记录时一直取最小值即可。

对于以下情况 $i\cdots j\cdots s_j\cdots s_i$

序列 $[i,s_i]$ 中存在不合法子序列 $[j,s_{j+1}],[j,s_{j+2}],\cdots,[j,s_i]$ ，所以右端点 $s_i$ 要左移到 $s_j$

即比 $i$ 大的数的最小右端点是 $s_i$，可以利用一个后缀最小值维护

时间复杂度： $O(n)$

```cpp
using ll = long long;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n + 1, n + 1); // s[i]表示区间[i, s[i]]所以对都是朋友
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        s[x] = min(s[x], y);
    }
    // 后缀最小值
    for (int i = n - 1; i >= 1; i--)
        if (s[i] > s[i + 1])
            s[i] = s[i + 1];
    for (int i = 1; i <= n; i++)
        ans += s[i] - i;
    cout << ans << endl;
}
```

