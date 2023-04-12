#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i < n; i++) {
        q.push({a[i], i});
    }

    vector<int> pre(n), nex(n);
    for (int i = 0; i < n; i++) {
        pre[i] = i - 1;
    }
    for (int i = 0; i < n; i++) {
        nex[i] = i + 1;
    }

    while (!q.empty()) {
        auto Top = q.top();
        int ai = Top.first;
        int i = Top.second;
        q.pop();
        if (ai != a[i]) {
            q.push({a[i], i});
            continue;
        }

        a[i] = -1;
        int Nex = nex[i];
        int Pre = pre[i];
        if (Nex < n) {
            a[Nex] += ai;
            pre[Nex] = Pre;
        }
        if (Pre >= 0) {
            a[Pre] += ai;
            nex[Pre] = Nex;
        }
        k--;
        if (k == 0) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            cout << a[i] << ' ';
        }
    }
    cout << '\n';

    return 0;
}