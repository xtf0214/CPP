/** 
 * @file    :   B
 * @author  :   Tanphoon 
 * @date    :   2024/05/29 00:48
 * @version :   2024/05/29 00:48
 * @link    :   https://codeforces.com/gym/105163/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<char, int>> v;
    for (int i = 0; i < n; i++) {
        if (v.size() == 0) {
            v.push_back({s[i], 1});
        } else if (s[i] == v.back().first) {
            v.back().second++;
        } else
            v.push_back({s[i], 1});
        if (v.size() && v.back().second == 3)
            v.pop_back();
    }
    for (auto [c, m] : v) {
        for (int i = 0; i < m; i++)
            cout << c;
    }
    if (!v.size())
        cout << "NAN\n";
}