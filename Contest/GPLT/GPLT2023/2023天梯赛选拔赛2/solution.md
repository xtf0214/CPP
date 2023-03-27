# 2023年第八届团队程序设计天梯赛

<h2 align='center'>选拔校赛（二）</h2>

<h3 align='center'>2023年3月25日</h3>

| 标号 | 标题                                                         | 知识点             | 分数 | 提交通过率     |
| ---- | ------------------------------------------------------------ | ------------------ | ---- | -------------- |
| 7-1  | [签到](https://pintia.cn/problem-sets/1639185874753327104/problems/1639286123308150784) | 输出               | 5    | 47/69(68.12%)  |
| 7-2  | [判断素数](https://pintia.cn/problem-sets/1639185874753327104/problems/1639286784070410240) | 素数判断           | 5    | 25/273(9.16%)  |
| 7-3  | [倒序输出](https://pintia.cn/problem-sets/1639185874753327104/problems/1639302978739527680) | 字符串             | 10   | 38/108(35.19%) |
| 7-4  | [学号核验](https://pintia.cn/problem-sets/1639185874753327104/problems/1639312131520356352) | 字符串             | 10   | 40/74(54.05%)  |
| 7-5  | [苹果与虫子](https://pintia.cn/problem-sets/1639185874753327104/problems/1639309250058678272) | 计算               | 15   | 38/124(30.65%) |
| 7-6  | [字符等边三角形](https://pintia.cn/problem-sets/1639185874753327104/problems/1639312131520356353) | 循环控制           | 15   | 44/58(75.86%)  |
| 7-7  | [吉老师的回归](https://pintia.cn/problem-sets/1639185874753327104/problems/1639311843757555712) | 字符串             | 20   | 15/178(8.43%)  |
| 7-8  | [机工士姆斯塔迪奥](https://pintia.cn/problem-sets/1639185874753327104/problems/1639323741915873280) | 模拟               | 20   | 23/227(10.13%) |
| 7-9  | [关于堆的判断](https://pintia.cn/problem-sets/1639185874753327104/problems/1639243179284918272) | 二叉堆             | 25   | 2/99(2.02%)    |
| 7-10 | [病毒溯源](https://pintia.cn/problem-sets/1639185874753327104/problems/1639243221878075392) | DFS深度优先搜索    | 25   | 2/48(4.17%)    |
| 7-11 | [网红点打卡攻略](https://pintia.cn/problem-sets/1639185874753327104/problems/1639243576745562112) | 图的基本概念与表示 | 25   | 1/19(5.26%)    |
| 7-12 | [社交集群](https://pintia.cn/problem-sets/1639185874753327104/problems/1639248660736933888) | 并查集             | 25   | 3/35(8.57%)    |
| 7-13 | [最短工期](https://pintia.cn/problem-sets/1639185874753327104/problems/1639345052302082048) | 拓扑排序           | 25   | 2/110(1.82%)   |
| 7-14 | [凑零钱](https://pintia.cn/problem-sets/1639185874753327104/problems/1639344694741856256) | DP动态规划         | 30   | 1/42(2.38%)    |
| 7-15 | [天梯地图](https://pintia.cn/problem-sets/1639185874753327104/problems/1639344813298061312) | 最短路径           | 30   | 0/14(0.00%)    |

# L1-1 签到

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "hello，china!";
    return 0;
}
```

# L1-2 判断素数

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool isPrime(ll x) {
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return x != 0 && x != 1;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        ll x;
        cin >> x;
        puts(isPrime(x) ? "Yes" : "No");
    }
}
```

# L1-3 倒序输出

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    while (s.back() == '0')
        s.pop_back();
    if (s[0] == '-') {
        reverse(s.begin() + 1, s.end());
    } else {
        reverse(s.begin(), s.end());
    }
    cout << s;
}
```

# L1-4 学号核验

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, flag = 1;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int m = stoi(s.substr(0, 2)); // 获取学号前两位，并转成整数
        if (m < 19 || m > 22) {
            flag = false;
            cout << s << endl;
        } else {
            for (int i = 0; i < s.size(); i++)
                if (!isdigit(s[i])) { //学号里有除了数字以外的字符
                    flag = false;
                    cout << s << endl;
                }
        }
    }
    if (flag)
        puts("OK");
}
```


# L1-5 苹果与虫子

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int m = ceil(1.0 * y / x);
    cout << max(0, n - m);
}
```


# L1-6 字符等边三角形

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    int n;
    cin >> c >> n;
    for (int i = 1; i <= n; i++)
        cout << string(n - i, ' ') << string(2 * i - 1, c) << endl;
}
```


# L1-7 吉老师的回归

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    vector<string> ans;
    cin >> n >> m;
    cin.get();
    while (n--) {
        string s;
        getline(cin, s);
        if (s.find("qiandao") != -1 || s.find("easy") != -1) // 存在"qiandao"或者"easy"的题目，吉老师会跳过
            continue;
        ans.push_back(s);
    }
    if (ans.size() <= m)
        cout << "Wo AK le";
    else
        cout << ans[m];
    return 0;
}
```

# L1-8 机工士姆斯塔迪奥

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<bool> row(n + 1), col(m + 1); // 两个bool数组，记录某行或列是否被删除
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 0 && !row[x]) {
            n--;
            row[x] = true;
        } else if (op == 1 && !col[x]) {
            m--;
            col[x] = true;
        }
    }
    cout << n * m;
    return 0;
}
```

# L2-1 关于堆的判断

使用 STL 函数 `push_heap()` 避免手写堆。`greater<int>()` 表示维护一个大根堆，`less<int>()`表示维护一个小根堆。

使用 `map<int, int>` 存储元素 `x` 在堆中的位置 `mp[x]`。

```cpp
#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
bool check() {
    int x, y;
    string s;
    cin >> x >> s;
    if (s == "and") { // x and y are siblings
        cin >> y >> s >> s;
        return mp[x] / 2 == mp[y] / 2;
    } else {
        cin >> s >> s;
        if (s == "root") { // x is the root
            return mp[x] == 1;
        } else if (s == "parent") { // x is the parent of y
            cin >> s >> y;
            return mp[x] == mp[y] / 2;
        } else if (s == "child") { // x is a child of y
            cin >> s >> y;
            return mp[y] == mp[x] / 2;
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> heap;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        heap.push_back(x);
        push_heap(heap.begin(), heap.end(), greater<int>());
    }
    for (int i = 0; i < n; i++)
        mp[heap[i]] = i + 1;
    while (m--)
        puts(check() ? "T" : "F");
    return 0;
}
```

# L2-2 病毒溯源

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;

int n, maxlen, src, dst; // src:起点  dst:最长路径的终点  maxlen:最长路径
vector<int> G[N];
int indeg[N], dep[N], pre[N]; // indeg:入度  dep:深度  pre:父节点

void dfs(int u) {
    for (int v : G[u]) {
        dep[v] = dep[u] + 1;
        pre[v] = u;
        if (maxlen < dep[v]) { // 更新长度更长的路径，设置当前节点为终点
            maxlen = dep[v];
            dst = v;
        }
        dfs(v);
    }
}
void print(int u) {
    if (u == -1)
        return;
    print(pre[u]);
    cout << u << " \n"[u == dst]; // 当u不是终点时空格分隔，u为终点时换行，行末空格引发防止格式错误
}
int main() {
    cin >> n;
    for (int u = 0, v, k; u < n; u++) {
        cin >> k;
        while (k--) {
            cin >> v;
            G[u].push_back(v);
            indeg[v]++;
        }
        sort(G[u].begin(), G[u].end()); // 题目要求长度相同优先输出序列小的，所以搜索子节点的顺序按照子节点大小排序
    }
    src = find(indeg, indeg + n, 0) - indeg; // 查找第一个入度为0的节点，即起点
    pre[src] = -1;
    dfs(src);
    cout << maxlen + 1 << endl; // +1是算上起点，起点的深度设置为0
    print(dst);
    return 0;
}
```


# L2-3 网红点打卡攻略

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;

int G[N][N], p[N];
bool vis[N];
int n, m, k;
set<pair<int, int>> st; // st保存{路径长度，序号}，按照路径长度的升序

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
    }
    cin >> k;
    for (int id = 1; id <= k; id++) {
        int len;
        cin >> len;
        for (int i = 1; i <= len; i++)
            cin >> p[i];
        p[len + 1] = 0;

        bool OK = true;
        int sum = 0;
        if (len != n)
            OK = false;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= len + 1; i++)
            if (G[p[i - 1]][p[i]] && !vis[p[i]]) {
                sum += G[p[i - 1]][p[i]];
                vis[p[i]] = true;
            } else
                OK = false;
        if (OK)
            st.insert({sum, id});
    }
    cout << st.size() << endl;
    cout << st.begin()->second << " " << st.begin()->first << endl;
}
```


# L2-4 社交集群

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

// 带权并查集，储存的是集合元素个数
struct DisjointSet {
    vector<int> p, val;
    DisjointSet(int n = 1e6) : p(n), val(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x != y)
            p[y] = x, val[x] += val[y];
    }
};

int n;
set<int> a[N]; // 保存每个人的爱好

int main() {
    cin >> n;
    DisjointSet ds(n + 1); // 并查集为存储人的集合
    for (int i = 1, sz; i <= n; i++) {
        cin >> sz;
        cin.get();
        while (sz--) {
            int x;
            cin >> x;
            a[i].insert(x);
            // 如果自己与其他人有共同爱好，则并入同一个集合
            for (int j = 1; j < i; j++)
                if (a[j].count(x))
                    ds.merge(i, j);
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (ds.find(i) == i) // 并查集的根节点，储存该集合内的人数
            ans.push_back(ds.val[i]);
    sort(ans.begin(), ans.end(), greater<int>()); // greater<int>控制逆序排序
    cout << ans.size() << endl; // 不同集合个数
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i + 1 == ans.size()]; // 行末无空格输出
    return 0;
}
```


# L3-1 最短工期

```cpp
#include <bits/stdc++.h>
using namespace std;
using Node = pair<int, int>;
const int N = 100 + 5;

int n, m;
vector<Node> G[N];
int indeg[N], oudeg[N], dist[N]; // 入度，出度，路径长度
vector<int> path;                // 记录路径

bool tsort() {
    queue<int> Q;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            Q.push(i);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        path.push_back(u);
        for (auto &[v, w] : G[u]) {
            if (--indeg[v] == 0)
                Q.push(v);
            dist[v] = max(dist[v], dist[u] + w);
        }
    }
    return path.size() == n;
}
int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        indeg[v]++;
        G[u].push_back({v, w});
    }
    if (tsort()) {
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (oudeg[i] == 0)
                ans = max(ans, dist[i]);
        cout << ans;
    } else {
        puts("Impossible");
    }
}
```
