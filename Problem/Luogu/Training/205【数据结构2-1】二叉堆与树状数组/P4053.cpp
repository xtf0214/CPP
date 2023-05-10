// P4053 建筑抢修
// https://www.luogu.com.cn/problem/P4053
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; // {报废时间，修复时间}
#define t2 first
#define t1 second
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, ans = 0;
    ll sum = 0;
    cin >> n;
    vector<pii> a(n);
    priority_queue<int> Qmax; // 修过的楼
    for (int i = 0; i < n; i++)
        cin >> a[i].t1 >> a[i].t2;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        sum += a[i].t1;
        ans++;
        Qmax.push(a[i].t1);
        if (sum > a[i].t2) {               // 时间不够
            sum -= Qmax.top(), Qmax.pop(); // 挑出修过的的最耗时的楼
            ans--;
        }
    }
    cout << ans;
    return 0;
}