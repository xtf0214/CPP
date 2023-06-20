/** 
 * @file    :   8 整数删除
 * @author  :   Tanphoon 
 * @date    :   2023/04/24 21:11
 * @version :   2023/04/24 21:11
 * @link    :   
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pli = pair<ll, int>;
const int N = 5e5 + 5;
ll a[N];
int pre[N], nxt[N];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    priority_queue<pli, vector<pli>, greater<pli>> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        pre[i] = i - 1;
        nxt[i] = i + 1;
        q.push({x, i});
    }
    while (k--) {
        while (a[q.top().second] != q.top().first) {
            q.pop();
        }
        ll ai = q.top().first;
        int i = q.top().second;
        q.pop();
        int p1 = pre[i];
        int p2 = nxt[i];
        a[i] = -1;
        pre[p2] = p1;
        nxt[p1] = p2;

        if (1 <= p1) {
            a[p1] += ai;
            q.push({a[p1], p1});
        }
        if (p2 <= n) {
            a[p2] += ai;
            q.push({a[p2], p2});
        }
    }
    for (int i = 1; i <= n; i++)
        if (a[i] != -1)
            cout << a[i] << " ";
    return 0;
}