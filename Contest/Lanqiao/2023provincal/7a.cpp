#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    long long ans = 0;
    cin >> k;
    string s;
    char a, b;
    cin >> s >> a >> b;
    int n = s.size();
    vector<int> sf(n + 1);
    for (int i = n - 1; i >= 0; i--)
        sf[i] = sf[i + 1] + (s[i] == b);
    for (int i = 0, j = k - 1; j < n; i++, j++) {
        if (s[i] == a)
            ans += sf[j];
    }
    cout << ans;
    return 0;
}
