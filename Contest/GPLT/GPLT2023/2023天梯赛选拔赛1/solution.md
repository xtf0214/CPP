# 2023年第八届团队程序设计天梯赛

<h2 align='center'>选拔校赛</h2>

<h3 align='center'>2023年3月18日</h3>

| 题目名                                    | 知识点              | 分值 |
| ----------------------------------------- | ------------------- | ---- |
| L1-1 Capital Letter X                     | 输出                | 5    |
| L1-2 再分肥宅水                           | 计算                | 5    |
| L1-3 ISBN号码                             | 判断                | 10   |
| L1-4 Fibonacci                            | 循环                | 10   |
| L1-5 津津的储蓄计划                       | 判断                | 15   |
| L1-6 矩阵转置                             | 二维数组            | 15   |
| L1-7 Polycarp Writes a String from Memory | 字符串              | 20   |
| L1-8 静静的推荐                           | 模拟                | 20   |
| L2-1 彩虹瓶                               | 栈                  | 25   |
| L2-2 点赞狂魔                             | 快速排序            | 25   |
| L2-3 任务调度的合理性                     | 拓扑排序            | 25   |
| L2-4 愿天下有情人都是失散多年的兄妹       | 深度优先搜索/并查集 | 25   |
| L3-1 千手观音                             | 拓扑排序、hash表    | 30   |
| L3-2 直捣黄龙                             | 最短路径            | 30   |
| L3-3 祖玛游戏                             | 区间动态规划（DP)   | 30   |

# L1-1 Capital Letter X

```cpp
#include <iostream>
using namespace std;
int main() {
    printf("\\  /\n");
    printf(" \\/\n");
    printf(" /\\\n");
    printf("/  \\\n");
    return 0;
}
```



# L1-2 再分肥宅水

```cpp
#include <iostream>
using namespace std;
int main() {
    double t;
    int n;
    cin >> t >> n;
    printf("%.3f\n%d", t / n, 2 * n);
    return 0;
}
```



# L1-3 ISBN号码

```cpp
#include <iostream>
using namespace std;
int main() {
    int k = 1, s = 0, p, q;
    string a;
    cin >> a;
    for (int i = 0; i < 12; i++)
        if (i != 1 && i != 5 && i != 11)
            s += int(a[i] - '0') * k++;

    p = (a[12] == 'X') ? 10 : int(a[12] - '0');

    if (p == s % 11) {
        cout << "Right";
    } else {
        for (int i = 0; i < 12; i++)
            cout << a[i];
        if (s % 11 == 10)
            cout << "X";
        else
            cout << s % 11;
    }
}
```

# L1-4 Fibonacci

```cpp
#include <iostream>
using namespace std;
int f[100005];
int main() {
    int n;
    cin >> n;
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++)
        f[i] = (f[i - 1] + f[i - 2]) % 100;
    printf("%02d", f[n]);
    return 0;
}
```




# L1-5 津津的储蓄计划

```cpp
#include <iostream>
using namespace std;
int main() {
    int i, k = 0, s = 0, x; // i表示月份，k表示每月剩余的钱，s表示存款，x表示预算
    for (i = 1; i <= 12; i++) {
        cin >> x;
        if (k + 300 - x >= 0) {
            s += (k + 300 - x) / 100 * 100;
            k = (k + 300 - x) % 100;
        } else {
            cout << "-" << i;
            return 0;
        }
    }
    cout << s * 1.2 + k;
    return 0;
}
```


# L1-6 矩阵转置

```cpp
#include <iostream>
using namespace std;
int a[25][25];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[j][i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
}
```


# L1-7 Polycarp Writes a String from Memory

```cpp
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int T;
    bool used[26];
    string s;
    cin >> T;
    while (T--) {
        cin >> s;
        int cnt = 0;
        memset(used, false, sizeof(used));
        for (char i : s)
            if (!used[i - 'a']) {
                cnt++;
                if (cnt % 3 == 1 && cnt != 1)
                    memset(used, false, sizeof(used));
                used[i - 'a'] = true;
            }
        cout << int(ceil(cnt / 3.0)) << endl;
    }
    return 0;
}
```


# L1-8 静静的推荐

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, m, s, ans = 0;
    int num[300] = {0};
    cin >> n >> m >> s;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a >= 175) {
            if (b >= s) // 特殊批次的考试
                ans++;
            else if (++num[a] <= m) // 同一分数的人，最多选择m个
                ans++;
        }
    }
    cout << ans;
    return 0;
}
```



# L2-1 彩虹瓶

```cpp
#include <iostream>
#include <stack>
using namespace std;

int n, m, k;
int x[1005];
bool solve() {
    int st = 1;
    stack<int> s;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++) {
        if (x[i] != st)
            s.push(x[i]);
        else
            st++;
        if (s.size() > m)
            return false;
        while (!s.empty() && s.top() == st) {
            st++;
            s.pop();
        }
    }
    return s.empty();
}
int main() {
    cin >> n >> m >> k;
    while (k--)
        puts(solve() ? "YES" : "NO");
}
```




# L2-2 点赞狂魔

```cpp
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct T {
    int num;
    string id;
    int cnt;
};
bool cmp(const T &a, const T &b) { return a.cnt != b.cnt ? a.cnt > b.cnt : a.num < b.num; }
T a[105];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        set<int> s;
        int x;
        cin >> a[i].id >> a[i].num;
        for (int j = 0; j < a[i].num; j++)
            cin >> x, s.insert(x);
        a[i].cnt = s.size();
    }
    sort(a, a + n, cmp);
    vector<string> ans(3, "-");
    for (int i = 0; i < min(n, 3); i++)
        ans[i] = a[i].id;
    for (int i = 0; i < 3; i++)
        cout << ans[i] << " \n"[i == 2];
    return 0;
}
```




# L2-3 任务调度的合理性

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 100 + 5;
int n;
vector<int> G[N];
int indeg[N];

bool tsort() {
    queue<int> q;
    vector<int> ans;
    for (int u = 1; u <= n; u++)
        for (int v : G[u])
            indeg[v]++;
    for (int u = 1; u <= n; u++)
        if (indeg[u] == 0)
            q.push(u);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v : G[u])
            if (--indeg[v] == 0)
                q.push(v);
    }
    return ans.size() == n;
}
int main() {
    cin >> n;
    for (int v = 1; v <= n; v++) {
        int m, u;
        cin >> m;
        while (m--) {
            cin >> u;
            G[u].push_back(v);
        }
    }
    cout << tsort();
}
```


# L2-4 愿天下有情人都是失散多年的兄妹

```cpp
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
vector<int> G[N];        // 存图
bool vis[N];             // 标记五服以内的亲属
char sex[N];             // 记录性别
bool flag;               // 标记情侣是否为近亲
void dfs(int u, int num) // num表示第几代，从1开始
{
    if (num >= 5) // 超过五代直接退出
        return;
    for (int v : G[u]) {
        if (!vis[v]) {
            vis[v] = true; // 标记出现的人
            dfs(v, num + 1);
        } else
            flag = 1; // 五服之内出现一样的人
    }
}
int main() {
    int n, T;
    cin >> n;
    while (n--) {
        int id, fa, ma;
        scanf("%d ", &id);
        sex[id] = getchar();
        scanf(" %d %d", &fa, &ma);
        if (fa != -1) {
            G[id].push_back(fa);
            sex[fa] = 'M';
        }
        if (ma != -1) {
            G[id].push_back(ma);
            sex[ma] = 'F';
        }
    }
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if (sex[x] == sex[y])
            cout << "Never Mind" << endl;
        else {
            memset(vis, 0, sizeof(vis));
            vis[x] = true;
            vis[y] = true;
            flag = 0;
            dfs(x, 1);
            dfs(y, 1);
            puts(flag ? "No" : "Yes");
        }
    }
    return 0;
}
```




# L3-1 千手观音

```cpp
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> deg;
unordered_map<string, vector<string>> G;

vector<string> split(string s, char p) {
    vector<string> res;
    s += p;
    for (int st = 0, i = 0; i < s.size(); i++)
        if (s[i] == p) {
            string word = s.substr(st, i - st);
            res.push_back(word);
            st = i + 1;
            if (!deg.count(word))
                deg[word] = 0;
        }
    return res;
}

vector<string> topsort() {
    priority_queue<string, vector<string>, greater<string>> Q;
    for (auto &[k, v] : deg)
        if (!v)
            Q.push(k);

    vector<string> res;
    while (!Q.empty()) {
        string t = Q.top();
        Q.pop();
        res.push_back(t);
        for (auto &p : G[t])
            if (--deg[p] == 0)
                Q.push(p);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    string str;
    cin >> n;

    vector<string> last;
    for (int i = 0; i < n; i++) {
        cin >> str;
        vector<string> cur = split(str, '.');
        if (i == 0) {
            last = cur;
            continue;
        }
        if (last.size() == cur.size()) {
            for (int j = 0; j < cur.size(); j++)
                if (last[j] != cur[j]) {
                    G[last[j]].push_back(cur[j]);
                    deg[cur[j]]++;
                    break;
                }
        }
        last = cur;
    }

    vector<string> res = topsort();
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ".\0"[i + 1 == res.size()];
    return 0;
}
```


# L3-2 直捣黄龙

```cpp
#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;

struct Node {
    string to;
    int dist;
    Node(string a, int b) : to(a), dist(b) {}
};

int n, k, i, j, num, Dist;
string self, enemy, str, str1;
map<string, int> m, sign;
map<string, vector<Node>> mmid;
typedef pair<int, string> P;
void dijkstra();
int main() {
    cin >> n >> k >> self >> enemy;
    for (i = 1; i < n; i++) {
        cin >> str >> num;
        m[str] = num;  // 敌人数
        sign[str] = 1; // 标记是否访问 1还没访问
    }
    m[self] = 0;
    sign[self] = 1;
    for (i = 0; i < k; i++) {
        cin >> str >> str1 >> Dist;
        mmid[str].push_back(Node(str1, Dist));
        mmid[str1].push_back(Node(str, Dist));
    }
    dijkstra();
    return 0;
}

// typedef pair<int, string> P;  first 代表到当前城市的最短距离，second代表城市
void dijkstra() {
    map<string, int> dist, CityCnt, EnemyCnt, road;
    priority_queue<P, vector<P>, greater<P>> que;
    map<string, string> Path; // first当前顶点，second当前节点的前驱节点
    vector<string> path;
    P p;
    string v, to, pre;
    int i, j;
    for (auto it = m.begin(); it != m.end(); it++) // 对各个数据初始化
    {
        dist[it->first] = INF;
        Path[it->first] = "";
        CityCnt[it->first] = 0;
        EnemyCnt[it->first] = 0;
        road[it->first] = 1;
    }
    Path[self] = "";
    dist[self] = 0;
    CityCnt[self] = 0;
    EnemyCnt[self] = 0;
    que.push(P(0, self));
    int cnt = 0;
    while (que.size()) {
        p = que.top();
        que.pop();
        v = p.second;
        if (sign[v] == 0)
            continue;
        sign[v] = 0;
        for (i = 0; i < mmid[v].size(); i++) {

            to = mmid[v][i].to;
            if (dist[v] + mmid[v][i].dist < dist[to]) {
                dist[to] = dist[v] + mmid[v][i].dist;
                Path[to] = v;
                CityCnt[to] = CityCnt[v] + 1;
                EnemyCnt[to] = EnemyCnt[v] + m[to];
                road[to] = road[v];

                que.push(P(dist[to], to));
            } else if (dist[v] + mmid[v][i].dist == dist[to]) {
                road[to] += road[v];
                if (CityCnt[v] + 1 > CityCnt[to]) {
                    Path[to] = v;
                    CityCnt[to] = CityCnt[v] + 1;
                    EnemyCnt[to] = EnemyCnt[v] + m[to];

                } else if (CityCnt[v] + 1 == CityCnt[to]) {
                    if (EnemyCnt[to] < EnemyCnt[v] + m[to]) {
                        Path[to] = v;
                        EnemyCnt[to] = EnemyCnt[v] + m[to];
                    }
                }
            }
        }
    }
    pre = Path[enemy];
    path.push_back(enemy);

    while (pre != "") {
        path.push_back(pre);
        pre = Path[pre];
    }

    reverse(path.begin(), path.end());
    int flag = 0;
    for (i = 0; i < path.size(); i++) {
        if (flag)
            cout << "->";
        cout << path[i];
        flag = 1;
    }
    cout << endl << road[enemy] << " " << dist[enemy] << " " << EnemyCnt[enemy];
}
```


# L3-3 祖玛游戏

```cpp
#include <iostream>
#include <cstring>
using namespace std;
const int N = 500 + 5;

int n;
int a[N];
int f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(f, 0x3f, sizeof(f));
    for (int L = 0; L < n; L++)
        for (int i = 1, j = i + L; j <= n; i++, j++) {
            if (a[i] == a[j])
                f[i][j] = (L < 2) ? 1 : min(f[i][j], f[i + 1][j - 1]);
            for (int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
        }
    cout << f[1][n];
    return 0;
}
```
