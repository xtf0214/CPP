/**
 * @file    :   1832A
 * @author  :   Tanphoon
 * @date    :   2023/06/23 18:16
 * @version :   2023/06/23 18:16
 * @link    :   https://codeforces.com/contest/1832/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

bool solve() {
    string s;
    cin >> s;
    int n = s.size();
    set<char> st;
    for (int i = 0; i < n / 2; i++) st.insert(s[i]);
    return st.size() > 1;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) puts(solve() ? "YES" : "NO");
    return 0;
}