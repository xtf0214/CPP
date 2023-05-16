> 题目链接：https://ac.nowcoder.com/acm/contest/57784/C
> 来源：牛客网

## 题目描述

> 有一个长度为 $n$ 的序列 $a_i$ 和常数 $K$。
>
> 总共选 $m$ 次，每次选一个连续区间 $[L_i,R_i]$ ，问这个区间中存在多少个**连续子区间**满足，区间中**不同的数**的个数**不小于** $K$。

首先用**尺取法**统计区间数字出现的次数，这是一种简单易行的暴力法。

定义 `mp[x]` 表示数字 $x$ 出现的次数；定义 `cnt` 表示区间内不同数的个数；定义 `f[i]` 表示区间 $[i, f_i]$ 中有 $k$ 个不同的数。

用指针 $l, r$ 单向扫描，从数列头扫到尾，$l, r$ 最终落在区间最右边。

$r$ 每向右扫描一个数字，它出现的次数加1；$l$ 每向右扫描一个数字，它出现的次数减1。

当 `cnt` 的值等于 $K$ 时，记录此时的右指针 $f[l]\gets r$。

```cpp
for (int l = 1, r = 1; l <= n; l++) {
    while (cnt < k && r <= n)
        if (++mp[a[r++]] == 1)
            cnt++;
    if (cnt == k)
        f[l] = r - 1;
    else
        f[l] = n + 1;
    if (--mp[a[l]] == 0)
        cnt--;
}
```

我们考虑如何计算子区间个数。

```cpp
for (int i = l; i <= r; i++)
	if (f[i] <= r)
		cnt += r - f[i] + 1;
```

考虑到 $f[i]$ 是单调递增的，那么可以二分查找 `p = upper_bound(r) - 1`

答案为 $(r+1)(p-l+1)-\sum\limits_{i=l}^{i\le p} f[i]=(r+1)(p-l+1)-(s[p]-s[l-1])$。$s[i]$ 为 $f[i]$ 的前缀和。

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

int a[N], f[N];
ll s[N];
int n, m, k, cnt;
map<int, int> mp;

void add(int x) {
    if (++mp[a[x]] == 1)
        cnt++;
}
void del(int x) {
    if (--mp[a[x]] == 0)
        cnt--;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 尺取法，f[i] 表示区间 [i, f[i]] 中有k个不同的数
    for (int l = 1, r = 1; l <= n; l++) {
        while (cnt < k && r <= n)
            add(r++);
        if (cnt == k)
            f[l] = r - 1;
        else
            f[l] = n + 1;
        del(l);
    }
    // 计算f的前缀和
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + f[i];

    ll ans = 0;
    while (m--) {
        ll l1, r1;
        cin >> l1 >> r1;
        int l = min(l1 ^ ans, r1 ^ ans) + 1;
        int r = max(l1 ^ ans, r1 ^ ans) + 1;
        // 二分
        ll p = upper_bound(f + 1, f + 1 + n, r) - f - 1;

        ans = 0;
        if (p >= l)
            ans = (r + 1) * (p - l + 1) - (s[p] - s[l - 1]);
        cout << ans << endl;
    }
}
```

