/**
 * @file    :   f 买车
 * @author  :   Tanphoon
 * @date    :   2023/05/17 11:01
 * @version :   2023/05/17 11:01
 * @link    :   https://ac.nowcoder.com/acm/contest/37160/F
 */
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define F first
#define S second

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    priority_queue<int> Qmax;
    vector<pii> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i].F >> a[i].S;
    sort(a.begin(), a.end());
    a.push_back({n, 0});
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (t < a[i].F) {                              // 当前的位置走不过去了
            if (!Qmax.empty() && Qmax.top() >= a[i].F) // 从前面的车中选一个能走最远的车
                t = Qmax.top(), ans++;
            else { // 前面最远的车也走不到这里，那么就是无解的
                cout << -1 << endl;
                return 0;
            }
        }
        Qmax.push(a[i].F + a[i].S); // 维护买前面的车最大能到达的位置
    }
    if (t >= n)
        cout << ans << endl;
    else
        cout << "-1" << endl;
    return 0;
}