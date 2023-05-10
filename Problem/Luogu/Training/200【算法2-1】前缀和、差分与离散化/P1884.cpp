// P1884 [USACO12FEB]Overplanting S
// https://www.luogu.com.cn/problem/P1884
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(v) v.begin(), v.end()

int n;
vvi a, f;
vi d;
ll ans;
map<int, int> Map;
void add(int i, int l, int r) { f[i][l]++, f[i][r]--; } // add [l,r)
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    a = vvi(n, vi(4));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
            d.push_back(a[i][j]);
        }
    // 离散化
    sort(all(d));
    d.erase(unique(all(d)), d.end());
    for (int i = 0; i < d.size(); i++)
        Map[d[i]] = i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            a[i][j] = Map[a[i][j]];
    // 差分区间加
    f = vvi(d.size(), vi(d.size()));
    for (auto &v : a)
        for (int i = v[0]; i < v[2]; i++)
            add(i, v[3], v[1]);
    for (int i = 0; i < d.size() - 1; i++)
        for (int j = 1; j < d.size() - 1; j++)
            f[i][j] += f[i][j - 1];
    // 统计答案
    for (int i = 0; i < d.size() - 1; i++)
        for (int j = 0; j < d.size() - 1; j++)
            if (f[i][j])
                ans += ll(d[i + 1] - d[i]) * (d[j + 1] - d[j]);
    cout << ans << endl;
    return 0;
}
