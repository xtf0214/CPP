// P4155 [SCOI2015]国旗计划
// https://www.luogu.com.cn/problem/P4155
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vvi = vector<vi>;
#define all(v) v.begin(), v.end()
#define lowbit(x) x &(-x)
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i++ == v.size() - 1])

int n, m, logn;
struct Soldier
{
    int l, r, id;
    Soldier(int l = 0, int r = 0, int id = 0) : l(l), r(r), id(id) {}
    bool operator<(const Soldier &t) { return l < t.l; }
};
vector<Soldier> seg;
vvi f;
vi res;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    logn = __lg(n * 2) + 1;
    seg.resize(n);
    f = vvi(2 * n, vi(logn + 1));
    res = vi(n);
    for (int i = 0, a, b; i < n; i++)
    {
        cin >> a >> b;
        b = a > b ? b + m : b;
        seg[i] = {a, b, i};
    }
    sort(all(seg));
    seg.resize(2 * n);
    for (int i = 0; i < n; i++)
        seg[i + n] = {seg[i].l + m, seg[i].r + m, seg[i].id};
    // 后一个相连线段
    for (int i = 0, p = 0; i < 2 * n; i++)
    {
        while (p < 2 * n && seg[p].l <= seg[i].r) //此处<=用的很妙，让区间最大利用
            p++;
        f[i][0] = p - 1;
    }
    // 倍增
    for (int t = 1; t <= logn; t++)
        for (int i = 0; i < 2 * n; i++)
            f[i][t] = f[f[i][t - 1]][t - 1];
    // 查询
    for (int i = 0; i < n; i++)
    {
        int lmt = seg[i].l + m, ans = 1, p = i;
        for (int t = logn; t >= 0; t--)
            if (f[p][t] != 0 && seg[f[p][t]].r < lmt)
            {
                ans += (1 << t);
                p = f[p][t];
            }
        res[seg[i].id] = ans + 1;
    }
    print(res);
    return 0;
}
