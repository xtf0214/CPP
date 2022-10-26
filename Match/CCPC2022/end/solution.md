# 2022CCPC河南省赛题解

### Problem E. Serval 的俳句

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, st = 0;
    int cnt[128]{0};
    int len[3]{5, 7, 5};
    char c[3];
    char x;
    cin >> n;
    if (n < 17)
        return (cout << "none", 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cnt[x]++;
        if (cnt[x] == len[st])
        {
            memset(cnt, 0, sizeof(cnt));
            c[st] = x;
            st++;
        }
    }
    if (st < 3)
        cout << "none";
    else
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < len[i]; j++)
                cout << c[i];
    return 0;
}
```

### Problem F. 集合之和

定义有限数集 $A$, $B$ 的加法为 $A+B=\{x+y\ |\ x\in A,y\in B\}$

给定 $n$，构造数集 $A$ 满足下列条件：

- $|A+A|=n,\ 1\le n\le 5\times 10^5$
- $\forall x\in A:x\in\mathbb{Z}\cap[0,5\times 10^5]$

注意到：

当 $A=\{1,2,\cdots ,k\}$时， $A+A=\{2,3,\cdots ,2k\}$ ， $|A+A|=2k-1$

当 $A=\{0,2,\cdots ,k\}$时， $A+A=\{0,2,3,\cdots ,2k\}$ ， $|A+A|=2k$

$2k-1\leqslant |A+A|\leqslant C_k^2 +k=\dfrac{k(k+1)}{2}$

可利用上述两种数列构造

```cpp
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i == v.size() - 1], ++i)

int main()
{
    int n, k;
    vi a;
    cin >> n;
    if (n == 2 || n == 4)
        return (cout << "-1", 0);
    else if (n & 1)
    {
        k = (n + 1) / 2;
        a.resize(k);
        iota(all(a), 1);
    }
    else
    {
        k = n / 2;
        a.resize(k);
        iota(all(a), 1);
        a[0] = 0;
    }
    cout << k << endl;
    print(a);
    return 0;
}
```

### Problem G. Mocha 上大班啦

对于每一列的**按位与运算**结果，如果中间值存在0，则结果一定为0，如果不存在0，则结果一定为1

对于每次操作，将 $s_j [x]$ 替换为 $s_j[x]$ & $s_i[x]$ ，0的个数只增不减，所以无论操作成功与失败，都没法改变某列**按位与运算**的结果

```cpp
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(v) v.begin(), v.end()

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m,q, ans = 0,l,r,i,j,p;
    char c;
    cin >> n >> m;
    vi b(m, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            if (c == '0' && b[j] != 0)
                b[j] = 0;
        }
    cin >> q;
    while(q--)
        cin >> i >> j >> l >> r >> p;
    cout << count(all(b), 1);
    return 0;
}
```

### Problem H. 旋转水管



```cpp
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define fi first
#define se second

int m, st, ed, flag;
int adjs[6] = {4, 1, 2, 3, 4, 1};
// the direction of next step [1:right, 2:down, 3:left, 4:up]
pii vec[5] = {{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<int> G[2];
vector<bool> vis[2];

// k is the source of water [1:left, 2:up, 3:right, 4:down]
void dfs(int y, int x, int k)
{
    if (y == 2 && x == ed - 1)
        return void(flag = 1);
    if (y < 0 || y >= 2 || x < 0 || x >= m || vis[y][x])
        return;
    vis[y][x] = true;
    if (5 <= G[y][x] && G[y][x] <= 6)
        dfs(y + vec[k].fi, x + vec[k].se, k);
    else if (1 <= G[y][x] && G[y][x] <= 4)
    {
        // k1,k2 is the direction of the next step
        int k1 = adjs[k - 1], k2 = adjs[k + 1];
        dfs(y + vec[k1].fi, x + vec[k1].se, k1);
        dfs(y + vec[k2].fi, x + vec[k2].se, k2);
    }
    vis[y][x] = false;
}
void solve()
{
    char c;
    cin >> m >> st >> ed;
    G[0].resize(m, 0), G[1].resize(m, 0);
    vis[0].resize(m), vis[1].resize(m);
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j < m; j++)
            cin >> c, G[i][j] = c == 'I' ? 5 : 1;
    flag = 0;
    dfs(0, st - 1, 2);
    puts(flag ? "YES" : "NO");
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}	
```

