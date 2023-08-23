#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> pv(n);
    for (auto &[a, b] : pv)
        cin >> a >> b;
    map<int, vector<int>> mp;
    for (int S = 1; S < (1 << n); S++) {
        int cnt = __builtin_popcount(S);
        vector<int> s;
        for (int i = 0; i < n; i++)
            if (S >> i & 1)
                s.push_back(i);
        int sum = 0, mx = 0;
        for (int i : s) {
            sum += pv[i].first;
            mx = max(mx, pv[i].second);
        }
        mp[cnt].push_back(sum + mx);
    }
    for (auto &[a, b] : mp) {
        cout << *min_element(b.begin(), b.end()) << '\n';
    }
}