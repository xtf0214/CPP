// P1955 [NOI2015] 程序自动分析
// https://www.luogu.com.cn/problem/P1955
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define all(v) v.begin(), v.end()

int n;
vector<pii> a, b; // a存储相等关系，b存储不等关系
vi d, p;          // d离散化数组，p并查集存储父节点
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
void merge(int x, int y) { find(x) != find(y) ? p[find(x)] = find(y) : 0; }
int get(int x) { return lower_bound(all(d), x) - d.begin(); }
void solve()
{
    cin >> n;
    for (int i = 0, u, v, w; i < n; i++)
    {
        cin >> u >> v >> w;
        w ? a.push_back({u, v}) : b.push_back({u, v});
        d.push_back(u);
        d.push_back(v);
    }
    sort(all(d));
    d.erase(unique(all(d)), d.end());
    for (auto &[u, v] : a)
        u = get(u), v = get(v);
    for (auto &[u, v] : b)
        u = get(u), v = get(v);
    p = vi(d.size());
    iota(all(p), 0);
    for (auto &[u, v] : a)
        merge(u, v);
    bool mk = true;
    for (auto &[u, v] : b)
        if (find(u) == find(v))
        {
            mk = false;
            break;
        }
    puts(mk ? "YES" : "NO");
    a.clear(), b.clear();
    d.clear();
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
