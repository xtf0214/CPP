#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define F first
#define S second
#define all(v) v.begin(), v.end()

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    priority_queue<int> Qmax;
    vector<pii> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i].F >> a[i].S;
    sort(all(a));
    a.push_back({n, 0});
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (t < a[i].F) {
            if (!Qmax.empty() && Qmax.top() >= a[i].F)
                t = Qmax.top(), ans++;
            else {
                cout << -1 << endl;
                return 0;
            }
        }
        Qmax.push(a[i].F + a[i].S);
    }
    if (t >= n)
        cout << ans << endl;
    else
        cout << "-1" << endl;
    return 0;
}