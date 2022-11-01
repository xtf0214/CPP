#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned ll;
using pii = pair<int, int>;
using vi = vector<int>;
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << (char[2][2]){" ", "\n"}[i == v.size() - 1], ++i)
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

void solve()
{
    ll x, k;
    cin >> x >> k;
    while (k--)
    {
        x++;
        if (x % 3 == 0)
            x /= 3;
    }
    cout << x;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}