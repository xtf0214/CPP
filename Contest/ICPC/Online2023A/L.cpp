#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, T;
    cin >> n >> T;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int t = *max_element(a.begin(), a.end());
    int ans = (t + T - 1) / T;
    cout << max(2LL, ans);
}