#include <bits/stdc++.h>
#define lowbit(x) x & -x
using namespace std;
using ll = long long;
const int N = 100 + 5;
void solve()
{
    int n;
    bool a[N]{0};
    int id[N]{0};
    ll x, t;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        t = __lg(t);
        a[t] = true;
        id[t] = i;
    }
    vector<int> ans;
    for (int i; x; x -= lowbit(x))
    {
        i = __lg(lowbit(x));
        if (!a[i])
            return void(cout << -1 << endl);
        ans.push_back(id[i]);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i : ans)
        cout << i << " ";
    cout << endl;
}
int main()
{
    int T, n;
    cin >> T;
    while (T--)
        solve();
    return 0;
}