// P1007 独木桥
// https://www.luogu.com.cn/problem/P1007
#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int L, n;
    cin >> L >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int maxT = 0, minT = 0;
    for (int i = 0; i < n; i++) {
        maxT = max(maxT, max(a[i], L + 1 - a[i]));
        minT = max(minT, min(a[i], L + 1 - a[i]));
    }
    cout << minT << " " << maxT;
    return 0;
}