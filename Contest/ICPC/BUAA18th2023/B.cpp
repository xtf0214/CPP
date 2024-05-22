#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    vector<ll> b(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(b.begin(), b.end());
    for (int i = 1; i <= m; i++)
        b[i] += b[i - 1];
    for (int i = 1; i <= n; i++) {
        int pos = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        pos--;
        cout << pos << ' ';
    }
}