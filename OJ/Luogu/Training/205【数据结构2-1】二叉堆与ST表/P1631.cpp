// P1631 序列合并
// https://www.luogu.com.cn/problem/P1631
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n), st(n, 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    priority_queue<pii, vector<pii>, greater<pii>> minHeap;
    for (int i = 0; i < n; i++)
        minHeap.push({a[i] + b[0], i});
    for (int i = 0; i < n; i++) {
        auto [val, src] = minHeap.top();
        minHeap.pop();
        cout << val << " ";
        minHeap.push({a[src] + b[st[src]++], src});
    }
    return 0;
}