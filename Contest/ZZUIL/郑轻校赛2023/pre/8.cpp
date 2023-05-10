#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int n = t, a[103]{0}, s0[103]{0}, s1[103]{0}, p0[106]{0}, p1[106]{0};
    // scanf("%d", &n);
    // n = 4;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        s0[i] = s0[i - 1];
        if (a[i] == 0)
            ++s0[i];
        s1[i] = s1[i - 1];
        if (a[i] == 1)
            ++s1[i];
    }

    for (int i = n; i >= 1; i--) {
        p1[i] = p1[i + 1];
        if (a[i] == 1)
            ++p1[i];
        p0[i] = p0[i + 1];
        if (a[i] == 0)
            ++p0[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = max({ans, s0[i] + p0[i + 1], s1[i] + p1[i + 1], s0[i] + p1[i + 1]});
    printf("%d\n", ans);
}
int main() {
    int t;
    while (cin >> t)
        solve(t);
    return 0;
 }