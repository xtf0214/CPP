#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mx = 0;
    for (int i = 0, j = 0; i < n && j < n;) {
        while (j < n && a[j] == a[i])
            j++;
        if (a[i] == 0)
            mx = max(mx, j - i);
        i = j;
    }
    cout << mx << '\n';
}

int main() {
    // freopen("D.in", "r", stdin);

    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) 
        solve();
}