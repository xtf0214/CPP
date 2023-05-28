#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 5;

int n;
int s[N];

int main() {
    cin >> n;
    for (int i = 2, u; i <= n; i++) {
        cin >> u;
        s[u]++;
    }
    i64 ans = 0;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        ans += a * (1 - s[i]);
    }
    cout << ans << endl;
}