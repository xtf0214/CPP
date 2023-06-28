#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<string, int> mp;
    while (n--) {
        int x;
        string s;
        cin >> x >> s;
        if (mp.count(s)) {
            mp[s] = min(mp[s], x);
        } else {
            mp[s] = x;
        }
    }
    int ans = 1e9;
    if (mp.count("11"))
        ans = mp["11"];
    if (mp.count("10") && mp.count("01"))
        ans = min(ans, mp["10"] + mp["01"]);
    if (ans == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}

int main() {
    // freopen("C.in", "r", stdin);

    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) 
        solve();
}