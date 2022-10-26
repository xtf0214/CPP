#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << (char[2][2]){" ", "\n"}[i == v.size() - 1], ++i)
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pii> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i].se >> a[i].fi;
    vi col(n), row(n);
    bool ok = true;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == i)
                continue;
            col[a[j].se - 1] = row[a[j].fi - 1] = 1;
        }
        if ((n - accumulate(all(row), 0)) * (n - accumulate(all(col), 0)) == 1)
        {
            ok = false;
            break;
        }
    }
    puts(ok ? "YES" : "NO");
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