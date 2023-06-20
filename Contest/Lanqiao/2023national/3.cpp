#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 5;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> vis(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    int modity = 0, single = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 2) {
            modity += a[i] - 2;
        }
        if (a[i] == 1) {
            single++;
        }
    }
    cout << modity + single / 2;
    return 0;
}