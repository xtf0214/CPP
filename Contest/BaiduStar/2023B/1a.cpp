#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef _DEBUG
#include "DEBUG.h"
#endif

int n;
vector<int> a[3], p[3];

// int extremum(int a, int b, const function<int(int)> f) {
//     int l = a - 1, r = b + 1;
//     while (r - l > 2) {
//         int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
//         (f(m1) > f(m2)) ? l = m1 : r = m2;
//     }
//     return (l + r) / 2;
// }

int extremum(int a, int b, const function<int(int)> f) {
    int l = a - 1, r = b + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        f(mid) - f(mid - 1) < 0 ? l = mid : r = mid;
    }
    return l;
}

signed main() {
    cin >> n;
    for (int d = 0; d < 3; d++)
        a[d].resize(n + 1), p[d].resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[0][i] >> a[1][i] >> a[2][i];

    vector<int> s(3), t(3);

    for (int d = 0; d < 3; d++) {
        auto &v = a[d], &pr = p[d];

        sort(v.begin() + 1, v.end());
        for (int i = 1; i <= n; i++)
            pr[i] = pr[i - 1] + v[i];

        auto f = [&](int x) {
            int s = 0;
            for (int i = 1; i <= n; i++)
                s += abs(v[i] - x);
            return s;
        };
        // s[d] = f(extremum(v[1], v[n], f));
        if (n & 1)
            s[d] = f(v[(1 + n) / 2]);
        else
            s[d] = f((v[n / 2] + v[n / 2 + 1]) / 2);

        auto g = [&](int x) {
            int l = 0, r = n + 1, mid;
            while (r - l > 1) {
                mid = (l + r) / 2;
                (v[mid] < x + mid - 1) ? l = mid : r = mid;
            }
            int ans = 0;
            ans += l * (x + x + l - 1) / 2 - (pr[l]);
            ans += (pr[n] - pr[l]) - (n - l) * (x + l + x + n - 1) / 2;
            return ans;
        };
        t[d] = g(extremum(v[1], v[n] - (n - 1), g));
    }
    // print(s);
    // print(t);
    int sum = s[0] + s[1] + s[2];
    int ans = 1e18;

    for (int i = 0; i < 3; i++)
        ans = min(ans, sum - s[i] + t[i]);
    cout << ans << '\n';
}