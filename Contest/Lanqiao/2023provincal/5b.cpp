#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> a(n + 1);
    vector<int> f(n + 1);
    vector<int> pre(10, -1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int res = INT_MIN;
    for (int i = 1; i <= n; i++) {
        int x = a[i].front() - '0', y = a[i].back() - '0';
        if (pre[x] == -1) {
            f[i] = 1;
        } else {
            f[i] = f[pre[x]] + 1;
        }
        res = max(res, f[i]);
        if (pre[y] == -1 || f[i] > f[pre[y]])
            pre[y] = i;
    }
    cout << n - res;
    return 0;
}