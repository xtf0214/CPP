# “卓见杯”郑州轻工业大学第十五届程序设计大赛暨河南省高校邀请赛

> 题目链接：[“卓见杯”郑州轻工业大学第十五届程序设计大赛暨河南省高校邀请赛](http://acm.zzuli.edu.cn/problemset.php?search=“卓见杯”郑州轻工业大学第十五届程序设计大赛暨河南省高校邀请赛)
>
> 大佬的题解：[“卓见杯”郑州轻工业大学第十五届程序设计大赛暨河南省高校邀请赛题解_WAWA源的博客-CSDN博客](http://t.csdn.cn/anAzA)
>
> | 题目                                                         | 算法           |
> | ------------------------------------------------------------ | -------------- |
> | [计算括号对](http://acm.zzuli.edu.cn/problem.php?id=3031)    | FFT            |
> | [最大子段和](http://acm.zzuli.edu.cn/problem.php?id=3032)    |                |
> | [最大的数](http://acm.zzuli.edu.cn/problem.php?id=3033)      | 贪心；DFS      |
> | [兔子爱吃胡萝卜](http://acm.zzuli.edu.cn/problem.php?id=3034) | DP：01背包     |
> | [小Z的难题](http://acm.zzuli.edu.cn/problem.php?id=3035)     | 字符串         |
> | [莫比乌斯最大值isUsefulAlgorithm](http://acm.zzuli.edu.cn/problem.php?id=3036) | 枚举；思维     |
> | [爆米花](http://acm.zzuli.edu.cn/problem.php?id=3037)        | 简单计算       |
> | [what&#39;s 莫比乌斯最大值](http://acm.zzuli.edu.cn/problem.php?id=3038) | 模拟；贪心     |
> | [神奇的花](http://acm.zzuli.edu.cn/problem.php?id=3039)      | 大模拟         |
> | [售卖车票](http://acm.zzuli.edu.cn/problem.php?id=3040)      | 贪心；区间维护 |
> | [Alice and Bob](http://acm.zzuli.edu.cn/problem.php?id=3041) | 模拟           |
> | [子序列](http://acm.zzuli.edu.cn/problem.php?id=3042)        |                |

# C 最大的数

n点n边，一定会出现环。使得经过的步数组成一个9位数最大，贪心地选择数字最大的点作为起点，走9步即为答案。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
string str;
int n, mx = 0, a[N], b[N];
vector<int> G[N];
vector<string> ans;

inline void dfs(int u, int cur) {
    if (cur > 9)
        return;
    str += b[u] + '0';
    for (int v : G[u])
        dfs(v, cur + 1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        mx = max(mx, b[i]);
    }
    if (mx == 0) {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        G[i].push_back(a[i]);
    for (int i = 1; i <= n; i++)
        if (b[i] == mx) {
            str.clear();
            dfs(i, 1);
            ans.push_back(str);
        }
    sort(ans.begin(), ans.end());
    cout << ans.back() << endl;
    return 0;
}
```

# D 兔子爱吃胡萝卜

状态：$f(i,j)$ 表示从前 $i$ 个数是否可以凑出 $s$ 满足 $s\equiv j\pmod n$

转移：$\left\{\begin{array}{l}
f(i,j)|=f(i-1,j)\ 不选第i个\\
f(i,(j+a_i)\%m)|=f(i-1,j)\ 选择第i个
\end{array}\right.$

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, a[1002], f[1002][1002];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
    }
    for (int i = 1; i <= n; i++) {
        f[i][a[i]] = 1;
        for (int j = 0; j < m; j++) {
            f[i][j] |= f[i - 1][j];
            f[i][(j + a[i]) % m] |= f[i - 1][j];
        }
    }
    if (f[n][0])
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
```

# E 小Z的难题

字符串般的高精度加，逢`z+1`进位

```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
char s[200006];

inline void check() {
    for (int i = n; i >= 1; i--) {
        if (s[i] > 'z')
            s[i] = 'a', s[i - 1] += 1;
        else
            break;
    }
}

int main() {
    cin >> n;
    scanf("%s", s + 1);
    int ok = 0;
    for (int i = n; i >= 1; i--)
        if (s[i] != 'z')
            ok = 1;
    if (!ok)
        printf("No solution\n");
    else {
        s[n] += 1;
        check();
        printf("%s", s + 1);
    }
    return 0;
}
```

# G 爆米花

简单数学签到。总爆米花数为 $1+2+\cdots +n=\dfrac{n(n+1)}{2}$。每次移动掉 $1$ 个，最后掉 $n-1$ 个，答案为 $\dfrac{n(n+1)}{2}-(n-1)$。

```cpp
#include <bits/stdc++.h>
using namespace std;

long long n, sum;

int main() {
    cin >> n;
    sum = (n + 1) * n / 2;
    sum -= n - 1;
    cout << sum <<endl;
    return 0;
}
```

# H what's 莫比乌斯最大值

如果输入的问题，则放在`问题set`里；如果是回答，则在`问题set`中最长与回答匹配的问题，标记该问题被回答。统计所有回答的问题的个数。

### 字典树Tire

使用`Tire`存储问题集合，回答后设置特殊标记

```cpp
// 102020 计科21——全局最优解队(司传钊\张青华\韩子昂)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int mxn = 1e6 + 100;
struct Trie {
    int nxt[mxn][26], exist[mxn];
    int cnt = 0;
    void clear() {
        cnt = 0;
        memset(nxt[0], 0, sizeof(nxt[0]));
        memset(exist, 0, sizeof(exist));
    }
    void insert(string s) {
        int u = 0;
        for (char ch : s) {
            ch -= 'a';
            if (!nxt[u][ch])
                nxt[u][ch] = ++cnt;
            u = nxt[u][ch];
        }
        ++exist[u];
    }
    int query(string s) {
        int u = 0, pos = -1;
        for (char ch : s) {
            ch -= 'a';
            if (!nxt[u][ch])
                break;
            u = nxt[u][ch];
            if (exist[u] > 0)
                pos = u;
        }
        if (pos != -1) {
            exist[pos] = -1e9;
            return 1;
        } else
            return 0;
    }
} trie;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "what's") {
            cin >> s;
            trie.insert(s);
        } else {
            ans += trie.query(s);
        }
    }
    cout << ans << '\n';
    return 0;
}
```

### set/unordered_set

在匹配问题时有几种思路：

- 按照回答的前缀**由长到短**去匹配问题，第一个匹配到的就是最长的问题。
- 遍历每一个问题，并在回答中截取相同长度的字串，如果匹配则更新此问题是否为最长问题。
- 从集合中逐一遍历，集合按照从问题长到短的顺序排序，从最长的问题开始匹配。

```cpp
// 301004 软工21——所以爱会消失对不队(马振刚\秦文杰\吕国凡)
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    unordered_set<string> que, ans;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "what's") {
            cin >> s;
            que.insert(s);
        } else {
            for (int j = s.size(); j > 0; j--) {
                string q = s.substr(0, j);
                if (que.count(q) && !ans.count(q)) {
                    ans.insert(q);
                    break;
                }
            }
        }
    }
    cout << ans.size();
}
```

```cpp
// 102032 计科22——有求无应队(刘家贤\吴宇扬\姬孟龙)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    unordered_set<string> que, ans;
    while (n--) {
        cin >> s;
        if (s == "what's") {
            cin >> s;
            que.insert(s);
        } else {
            string mxque;
            for (auto &q : que) {
                string t = s.substr(0, q.size());
                if (t == q && !ans.count(q)) {
                    if (mxque.size() < q.size())
                        mxque = q;
                }
            }
            if (mxque.size()) {
                ans.insert(mxque);
            }
        }
    }
    cout << ans.size();
    return 0;
}
```

`set`按照字典序逆序，相同前缀会首先匹配长度最长的问题。

```cpp
#include <bits/stdc++.h>
using namespace std;
int n;
set<string, greater<string>> que;
set<string> ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "what's") {
            cin >> s;
            que.insert(s);
        } else {
            for (auto &q : que)
                if (s.substr(0, q.size()) == q && !ans.count(q)) {
                    ans.insert(q);
                    break;
                }
        }
    }
    cout << ans.size();
    return 0;
}
```

# K Alice and Bob

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(string sx, string sy, ll &dist) {
    if (sx.size() > 6 || sy.size() > 6)
        return false;
    ll x = stoi(sx), y = stoi(sy);
    dist = x * x + y * y;
    return dist <= 1000000;
}
int main() {
    string x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll d1 = 0, d2 = 0;
    bool ok1 = check(x1, y1, d1);
    bool ok2 = check(x2, y2, d2);
    if (!ok1 && !ok2)
        cout << "Draw";
    else if (!ok1)
        cout << "Bob";
    else if (!ok2)
        cout << "Alice";
    else {
        if (d1 == d2)
            cout << "Draw";
        else if (d1 < d2)
            cout << "Alice";
        else
            cout << "Bob";
    }
    return 0;
}
```

