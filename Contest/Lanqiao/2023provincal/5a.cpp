#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(1);
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        a.push_back({s.front() - '0', s.back() - '0'});
    }
    int res = INT_MIN;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j].second == a[i].first)
                f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);
    }
    cout << n - res;
    return 0;
}