> 题目链接：https://ac.nowcoder.com/acm/contest/58860
>
> 来源：牛客网

## 题目描述

> 给 $n$ 个集合 $S_1, S_2,\cdots ,S_n$ , 求所有区间的集合的并。
>

每个集合中元素只有 $m$ 种。

我们预处理每个元素在哪些集合出现。

```cpp
for (int i = 1, t; i <= n; i++) {
    cin >> t;
    for (int j = 1, x; j <= t; j++) {
        cin >> x;
        p[x].push_back(i);
    }
}
for (int i = 1; i <= m; i++)
    reverse(p[i].begin(), p[i].end());
```

以每个点为左端点，变化右端点能得到的不同集合也就最多 $m$ 种。记录下来每种元素第一次出现的位置，从预处理的信息中可以知道，并保存其位置和元素种类。

```cpp
for (int i = 1; i <= n; i++) {
    bitset<100> cur;
    vector<pair<int, int>> pos;
    for (int j = 1; j <= m; j++) {
        while (!p[j].empty() && p[j].back() < i)
            p[j].pop_back();
        if (!p[j].empty())
            pos.emplace_back(p[j].back(), j); // 从i开始计算，j物品最小出现的车厢编号
    }
```

我们将位置按照升序排序，每向后走一个车厢，都把从 $i$ 到当前车厢的物品序列，以 `bitset<100>` 存储在 `set` 里。

```cpp
sort(pos.begin(), pos.end());
for (int j = 0; j < pos.size(); j++) {
    auto [id, v] = pos[j];
    cur[v - 1] = 1;
    // 每向后走一个车厢，都记录一下从i到当前车厢所产生的物品序列
    if (j == pos.size() - 1 || pos[j].first != pos[j + 1].first)
        st.insert(cur);
}
```

时间复杂度: $O(nm)$

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> p(m + 1);
    for (int i = 1, t; i <= n; i++) {
        cin >> t;
        for (int j = 1, x; j <= t; j++) {
            cin >> x;
            p[x].emplace_back(i);
        }
    }
    for (int i = 1; i <= m; i++)
        reverse(p[i].begin(), p[i].end());
    // p[i]: 物品i在哪些车厢里，降序
    unordered_set<bitset<100>> st;
    for (int i = 1; i <= n; i++) {
        bitset<100> cur;
        vector<pair<int, int>> pos;
        for (int j = 1; j <= m; j++) {
            while (!p[j].empty() && p[j].back() < i)
                p[j].pop_back();
            if (!p[j].empty())
                pos.emplace_back(p[j].back(), j); // 从i开始计算，j物品最小出现的车厢编号
        }
        sort(pos.begin(), pos.end());
        for (int j = 0; j < pos.size(); j++) {
            auto [id, v] = pos[j];
            cur[v - 1] = 1;
            // 每向后走一个车厢，都记录一下从i到当前车厢j所产生的物品序列
            if (j == pos.size() - 1 || pos[j].first != pos[j + 1].first)
                st.insert(cur);
        }
    }
    cout << st.size() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();

    return 0;
}
```

