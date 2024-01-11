/**
 * @file    :   C
 * @author  :   Tanphoon
 * @date    :   2024/01/11 21:42
 * @version :   2024/01/11 21:42
 * @link    :   https://codeforces.com/contest/1714/problem/C
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    /*
    9 9
    17 89
    24 789
    30 6789
    35 56789
    39 456789
    42 3456789
    44 23456789
    45 123456789
     */
    vector<int> a;
    map<int, string> mp;
    string t = "9";
    for (int i = 9, s = 9; i >= 1; i--, s += i, t += (i + '0')) {
        a.push_back(s);
        mp[s] = t;
    }
    int x;   cin >> x;
    int y = *lower_bound(a.begin(), a.end(), x);
    string s = mp[y]; 
    s.back() = s.back() + (x - y);
    reverse(s.begin(), s.end());
    cout << s << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}