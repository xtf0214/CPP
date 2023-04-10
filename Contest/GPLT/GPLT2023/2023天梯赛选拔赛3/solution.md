# 2023年第八届团队程序设计天梯赛

<h2 align='center'>选拔校赛（三）</h2>

<h3 align='center'>2023年4月1日</h3>

| 标号 | 标题                                                         | 分数 | 提交通过率     |
| ---- | ------------------------------------------------------------ | ---- | -------------- |
| 7-1  | [认识时钟](https://pintia.cn/problem-sets/1641803555327336448/problems/1641805128895991808) | 5    | 36/99(36.36%)  |
| 7-2  | [修剪灌木](https://pintia.cn/problem-sets/1641803555327336448/problems/1641813747637055488) | 5    | 30/103(29.13%) |
| 7-3  | [求和运算](https://pintia.cn/problem-sets/1641803555327336448/problems/1641819946155667456) | 10   | 29/81(35.80%)  |
| 7-4  | [合并数组](https://pintia.cn/problem-sets/1641803555327336448/problems/1641836991312203776) | 10   | 27/127(21.26%) |
| 7-5  | [骰子游戏](https://pintia.cn/problem-sets/1641803555327336448/problems/1641865078619934720) | 15   | 14/94(14.89%)  |
| 7-6  | [字符串最大跨距](https://pintia.cn/problem-sets/1641803555327336448/problems/1641871911938064384) | 15   | 16/116(13.79%) |
| 7-7  | [走楼梯升级版](https://pintia.cn/problem-sets/1641803555327336448/problems/1641872693953458176) | 20   | 21/96(21.88%)  |
| 7-8  | [A-B](https://pintia.cn/problem-sets/1641803555327336448/problems/1641873472760221696) | 20   | 25/95(26.32%)  |
| 7-9  | [括号匹配](https://pintia.cn/problem-sets/1641803555327336448/problems/1641873926814601216) | 25   | 3/155(1.94%)   |
| 7-10 | [列出连通集](https://pintia.cn/problem-sets/1641803555327336448/problems/1641874382819323904) | 25   | 5/25(20.00%)   |
| 7-11 | [秀恩爱分得快](https://pintia.cn/problem-sets/1641803555327336448/problems/1641874599744540672) | 25   | 0/40(0.00%)    |
| 7-12 | [哲哲打游戏](https://pintia.cn/problem-sets/1641803555327336448/problems/1641875829141180416) | 25   | 4/18(22.22%)   |
| 7-13 | [喊山](https://pintia.cn/problem-sets/1641803555327336448/problems/1641876224848596992) | 30   | 1/28(3.57%)    |
| 7-14 | [地铁一日游](https://pintia.cn/problem-sets/1641803555327336448/problems/1641876424585535488) | 30   | 0/6(0.00%)     |
| 7-15 | [可怜的复杂度](https://pintia.cn/problem-sets/1641803555327336448/problems/1641876646841712640) | 30   | 0/13(0.00%)    |

# 7-1 认识时钟

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << (n - 1 + 3) % 12 + 1;
    return 0;
}
```

# 7-2 修剪灌木

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cout << max({i, 2 * (i - 1), 2 * (n - i)});
}
```

# 7-3 求和运算

重现赛中加了一个 $10^5$ 的测试点，本来这题要考前缀和的，以为 $10^4$ 的测试点能卡时间，没想到暴力也过了。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
long long pr[N], sum;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pr[i] = pr[i - 1] + a[i];
    }
    for (int i = 2; i <= n; i++)
        sum += a[i] * pr[i - 1];
    cout << sum;
    return 0;
}
```

# 7-4 合并数组

`unique` 对有序的数组进行去重，返回去重后的数组的end指针

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 20000 + 5;
int a[N];
int main() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> a[n + i];
    sort(a, a + n + m);
    int l = unique(a, a + n + m) - a;
    for (int i = 0; i < l; i++)
        cout << a[i] << " ";
    return 0;
}
```

# 7-5 骰子游戏

思路1：dfs深搜+剪枝，时间复杂度 $O(6^m)$

```cpp
#include <bits/stdc++.h>
using namespace std;

int k, m, n, ans;

void dfs(int m, int s) {
    if (s > n)
        return;
    if (m == 0) {
        if (s == n)
            ans++;
        return;
    }
    for (int i = 1; i <= 6; i++)
        dfs(m - 1, s + i);
}
int main() {
    cin >> k;
    while (k--) {
        cin >> m >> n;
        ans = 0;
        dfs(m, 0);
        printf("%.2lf", ans / pow(6, m));
    }
}
```

思路2：用大量随机数模拟摇骰子的结果。因为**在样本数足够大的情况下，可以用事件的频率来代替概率**

```cpp
#include <bits/stdc++.h>
using namespace std;

int k, m, n, ans;

bool randtest() {
    int res = 0;
    for (int i = 1; i <= m; i++)
        res += rand() % 6 + 1; // 生成[1,6]区间内的随机数
    return res == n;
}
int main() {
    cin >> k;
    while (k--) {
        cin >> m >> n;
        int ans = 0;
        for (int i = 1; i <= 1000000; i++)
            if (randtest())
                ans++;
        printf("%.2lf\n", ans / 1000000.0);
    }
}
```

# 7-6 字符串最大跨距

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, a, b;
    cin >> s;
    stringstream strin(s); // 使用字符串流去获取','分隔的字符串
    vector<string> res;
    while (getline(strin, s, ','))
        res.push_back(s);
    s = res[0], a = res[1], b = res[2];
    int p1 = s.find(a), p2 = s.rfind(b);
    if (p1 != -1 && p2 != -1)
        cout << p2 - (p1 + a.size());
    else
        cout << -1;
    return 0;
}
```

这题python的写法更优雅

```python
s, a, b = input().split(',')
p1 = s.find(a)
p2 = s.rfind(b)
if p1 != -1 and p2 != -1:
    print(p2 - (p1 + len(a)))
else:
    print(-1)
```

# 7-7 上台阶

```cpp
#include <bits/stdc++.h>
using namespace std;
long long f[200];
int main() {
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    int n;
    cin >> n;
    for (int i = 4; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    cout << f[n];
}
```

# 7-8 A-B

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b, ans;
    set<char> s;
    getline(cin, a);
    getline(cin, b);
    for (char c : b)
        s.insert(c);
    for (char c : a)
        if (!s.count(c))
            ans.push_back(c);
    cout << ans;
}
```

# 7-9 括号匹配

```cpp
#include <bits/stdc++.h>
using namespace std;

map<char, char> mp;
string solve() {
    string s;
    cin >> s;
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else {
            if (st.empty()) {
                return "Extra right brackets";
            } else if (!st.empty() && mp[st.top()] == c) {
                st.pop();
            } else {
                return "Brackets not match";
            }
        }
    }
    if (st.size())
        return "Extra left brackets";
    else
        return "Brackets match";
}
int main() {
    mp['('] = ')';
    mp['['] = ']';
    mp['{'] = '}';
    cout << solve();
    return 0;
}
```

# 7-10 列出连通集

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
vector<int> G[N];
int vis[N];
int n, m, cnt;

void dfs(int u, int t) {
    if (vis[u])
        return;
    vis[u] = t;
    cout << u << " ";
    for (int v : G[u])
        dfs(v, t);
}
void bfs(int u, int t) {
    queue<int> Q;
    Q.push(u);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (vis[u])
            continue;
        vis[u] = t;
        cout << u << " ";
        for (int v : G[u])
            Q.push(v);
    }
}
int main() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int u = 0; u < n; u++)
        sort(G[u].begin(), G[u].end()); // 按编号递增的顺序访问邻接点

    cnt = 0;
    memset(vis, 0, sizeof(vis));
    for (int u = 0; u < n; u++) {
        if (!vis[u]) {
            cout << "{ ";
            dfs(u, ++cnt);
            cout << "}\n";
        }
    }
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    for (int u = 0; u < n; u++)
        if (!vis[u]) {
            cout << "{ ";
            bfs(u, ++cnt);
            cout << "}\n";
        }
}
```

# 7-12 哲哲打游戏

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int rec[N];
vector<int> choice[N];
int n, m;
int now = 1;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        choice[i].resize(k + 1);
        for (int j = 1; j <= k; j++)
            cin >> choice[i][j];
    }
    for (int i = 1; i <= m; i++) {
        int op, j; // op是option的缩写, not Genshin (雾
        cin >> op >> j;
        if (op == 0) {
            now = choice[now][j]; // 转移
        } else if (op == 1) {
            rec[j] = now; // 存档
            cout << now << endl;
        } else if (op == 2) {
            now = rec[j]; // 读档
        }
    }
    cout << now;
    return 0;
}
```

# 7-13 喊山

考试的时候想到用 Dijkstra 跑一遍最短路，把每条边权设置为1，超时了，但是运气好得了大部分分（22/25）

```cpp
#include <bits/stdc++.h>
using namespace std;
using Edge = pair<int, int>;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;

vector<Edge> G[N];
int dist[N];
bool vis[N];
int n, m, k;

void dijkstra(int s) {
    memset(vis, 0, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    int maxdist = 0, idx = 0;
    while (true) {
        int u = -1, minv = INF;
        for (int i = 1; i <= n; i++)
            if (minv > dist[i] && !vis[i])
                u = i, minv = dist[i];
        if (u == -1)
            break;
        vis[u] = true;
        for (auto &[v, w] : G[u])
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (maxdist < dist[v]) {
                    maxdist = dist[v];
                    idx = v;
                } else if (maxdist == dist[v])
                    idx = min(idx, v);
            }
    }
    cout << idx << endl;
}
int main() {
    cin >> n >> m >> k;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].push_back({b, 1});
        G[b].push_back({a, 1});
    }
    for (int i = 0, t; i < k; i++) {
        cin >> t;
        dijkstra(t);
    }
    return 0;
}
```

考完回来想到是不是可以用堆优化的Dijkstra，交一遍然后过了

```cpp
#include <bits/stdc++.h>
using namespace std;
using Edge = pair<int, int>;
using Node = pair<int, int>;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;

vector<Edge> G[N];
int dist[N];
int n, m, k;

void dijkstra(int s) {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    int maxdist = 0, idx = 0;
    priority_queue<Node, vector<Node>, greater<Node>> q;
    q.push({0, s});
    while (!q.empty()) {
        auto [dist_u, u] = q.top();
        q.pop();
        if (dist[u] < dist_u)
            continue;
        for (auto &[v, w] : G[u])
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
                if (maxdist < dist[v]) {
                    maxdist = dist[v];
                    idx = v;
                } else if (maxdist == dist[v])
                    idx = min(idx, v);
            }
    }
    cout << idx << endl;
}
int main() {
    cin >> n >> m >> k;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].push_back({b, 1});
        G[b].push_back({a, 1});
    }
    for (int i = 0, t; i < k; i++) {
        cin >> t;
        dijkstra(t);
    }
    return 0;
}
```

后面再去看大佬的提交，发现其实BFS就能跑出来。也想起来从哪里看的，边权相同的图，跑堆优化Dijkstra自动退化成BFS了

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;

vector<int> G[N];
int dist[N];
int n, m, k;

void bfs(int s) {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    int maxdist = 0, idx = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u])
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (maxdist < dist[v]) {
                    maxdist = dist[v];
                    idx = v;
                } else if (maxdist == dist[v])
                    idx = min(idx, v);
            }
    }
    cout << idx << endl;
}
int main() {
    cin >> n >> m >> k;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0, t; i < k; i++) {
        cin >> t;
        bfs(t);
    }
    return 0;
}
```

重新看来一遍最短路专题

| 问题                 | 边权                        | 算法                     | 时间复杂度                 |
| -------------------- | --------------------------- | ------------------------ | -------------------------- |
| 一个起点，一个终点   | 非负数；无边权（或边权为1） | $A^*$ 算法               | $<O((m+n)\log n)$          |
|                      |                             | 双向广搜                 | $<O((m+n)\log n)$          |
|                      |                             | 贪心最优搜索             | $<O(m+n)$                  |
| 一个起点到其他所有点 | 无边权                      | BFS                      | $O(m+n)$                   |
|                      | 非负数                      | Dijkstra；堆优化Dijkstra | $O(n^2)$；$O((m+n)\log n)$ |
|                      | 允许有负数                  | Bellman-Ford；SPFA       | $<O(mn)$                   |
| 所有点对之间         | 允许有负数                  | Floyd-Warshall           | $O(n^3)$                   |

暂时先写这些，后面再补充:）