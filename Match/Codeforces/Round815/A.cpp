#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int solve()
{
    double a, b, m, n;
    int ans = 0;
    cin >> a >> b >> m >> n;
    if (a * n == b * m)
        return 0;
    else if (a * n / (b * m) == int(a * n / (b * m)) || b * m / (a * n) == int(b * m / (a * n)))
        return 1;
    else
        return 2;
}
int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}