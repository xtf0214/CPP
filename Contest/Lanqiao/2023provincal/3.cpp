#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int T;
    cin >> T;
    int mx = INT_MAX, mn = -INT_MAX;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int r = a / b;
        int i;
        for (i = 1; a / (r + i) == b; i++)
            ;
        mx = min(mx, (r + i - 1));

        for (i = 1; a / (r - i) == b; i++)
            ;
        mn = max(mn, (r - i + 1));
    }
    cout << mn << " " << mx;
    return 0;
}
