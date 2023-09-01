#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
int f[N], g[N];
ll s[N];
ll H(int n) {
    ll res = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
        int d = n / l;
        r = n / d;
        // res += ll(r - l + 1) * d;
        res += (s[r] - s[l - 1]) * g[d];
    }
}