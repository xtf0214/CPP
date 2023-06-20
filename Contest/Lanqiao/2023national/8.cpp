#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6 + 5;
int n, m;
int o[N], p[N];

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        o[(l + r)]++;
    }
    for (int i = 1; i <= N; i++) 
        p[i] = p[i - 1] + o[i];
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        cout << p[b * 2] - p[a * 2 - 1] << endl;
    }
    return 0;
}