/**
 * @file    :   A. Musical Puzzle
 * @author  :   Tanphoon
 * @date    :   2023/05/21 23:48
 * @version :   2023/05/21 23:48
 * @link    :   https://codeforces.com/contest/1833/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin >> n;
    string s;
    set<string> st;
    cin >> s;
    for (int i = 0; i + 1 < s.size(); i++) {
        st.insert(s.substr(i, 2));
    }
    return st.size();
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}