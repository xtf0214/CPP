/**
 * @file    :   2013C
 * @author  :   Tanphoon
 * @date    :   2024/09/21 15:40
 * @version :   2024/09/21 15:40
 * @link    :   https://codeforces.com/contest/2013/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include <DEBUG.h>
#define INTERACT
#else
#define debug(...) 0
#endif
const int N = 1e6 + 5;
#ifdef INTERACT
string t;
int query(string s) {
    if (t.find(s) != -1) {
        return 1;
    } else {
        return 0;
    }
}
#else
int query(string s) {
    cout << "? " << s << endl;
    int ans;
    cin >> ans;
    return ans;
}
#endif

inline void solve() {
    int n;
    cin >> n;
    #ifdef INTERACT
        cin >> t;
    #endif
    bool end = false;
    string s;
    while (s.size() < (ll)n) {
        if (end) {
            if (query("0" + s)) {
                s = "0" + s;
            } else {
                s = "1" + s;
            }
            continue;
        }
        if (query(s + "0")) {
            s = s + "0";
        } else if (s.size() == 0 || query(s + "1")) {
            s = s + "1";
        } else {
            end = true;
            continue;
        }
    }
    cout << "! " << s << endl;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}