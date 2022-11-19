#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T>
using vT = vector<T>;
template <typename T>
using vvT = vector<vector<T>>;
#define all(v) v.begin(), v.end()
#define lowbit(x) x &(-x)
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i++ == v.size() - 1])
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
const int N = 1e9 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int solve()
{
    ll l, x, r, a, b;
    vT<bool> vis(N);
    cin >> l >> r >> x >> a >> b;
    ll y = max(2 * x, abs(a - b));
    queue<pii> Q;
    Q.push({a, 0});
    while (!Q.empty())
    {
        auto [u, s] = Q.front();
        Q.pop();
        if (u == b)
            return s;
        for (int i = x; i <= y; i++)
        {
            if (u + i > r && u - i < l)
                break;
            if (!vis[u + i] && u + i <= r)
            {
                vis[u + i] = true;
                Q.push({u + i, s + 1});
            }
            if (!vis[u - i] && u - i >= l)
            {
                vis[u - i] = true;
                Q.push({u - i, s + 1});
            }
        }
    }
    return -1;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        cout << "ans=" << solve() << endl;
    return 0;
}