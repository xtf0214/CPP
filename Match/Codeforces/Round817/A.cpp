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
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i == v.size() - 1], ++i)
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

bool solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool used[128];
    used['T'] = used['i'] = used['m'] = used['u'] = used['r'] = true;
    if (s.size() != 5)
        return false;
    int cnt = 0;
    for (auto i : s)
        if (used[i])
            cnt++, used[i] = false;
    return cnt == 5 ? true : false;
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        puts(solve() ? "YES\n" : "NO\n");
    return 0;
}