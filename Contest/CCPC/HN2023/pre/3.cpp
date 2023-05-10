#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int t = 1;
        for (int j = 0; j < n; j++)
            t &= s[j][i];
        if (t == 1)
            ans++;
    }
    cout << ans << endl;
}