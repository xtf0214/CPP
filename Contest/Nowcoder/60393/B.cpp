#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int bitWidth(int x) { return 32 - __builtin_clz(x - 1); }

bool solve() {
    int n;
    cin >> n;
    if (n == 1)
        cout << 0 << '\n';
    else
        cout << bitWidth(n) << '\n';
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}