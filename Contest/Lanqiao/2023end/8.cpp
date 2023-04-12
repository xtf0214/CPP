#include <bits/stdc++.h>

#include "Timer.hpp"
#include "_DEBUG.h"
using namespace std;
#define dbg(x) cerr << "\033[0;31m" << #x << " = " << x << ";\033[0m"

typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e5 + 5;
ll a[N];
int pre[N], nxt[N];
int main() {
    Timer timer;
    timer.start();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        pre[i] = i - 1;
        nxt[i] = i + 1;
        q.push({x, i});
    }
    cout << timer.get().total << endl;
    while (k--) {
        while (a[q.top().second] != q.top().first) {
            q.pop();
        }
        dbg(q.size());
        int val = q.top().first, idx = q.top().second;
        q.pop();
        int p1 = pre[idx];
        int p2 = nxt[idx];
        a[idx] = -1;
        pre[p2] = p1;
        nxt[p1] = p2;

        if (1 <= p1) {
            a[p1] += val;
            q.push({a[p1], p1});
        }
        if (p2 <= n) {
            a[p2] += val;
            q.push({a[p2], p2});
        }
    }
    for (int i = 1; i <= n; i++)
        if (a[i] != -1)
            cout << a[i] << " ";
    return 0;
}
