/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2023/12/23 14:20
 * @version :   2023/12/23 14:20
 * @link    :   https://codeforces.com/gym/103104/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

string hexToBin(string s) { return bitset<4>(stoi(s, nullptr, 16)).to_string(); }

inline void solve() {
    string p, q;
    cin >> q >> p;
    int k = q.size(), n = p.size() * 4;
    basic_string<int> valp;
    for (int i = 0; i < p.size(); i++) {
        for (char c : hexToBin(p.substr(i, 1)))
            valp.push_back(c - '0');
    }
    valp += basic_string<int>(k - 1, 0);
    basic_string<int> valq;
    for (char c : q)
        valq.push_back(c - '0');
    basic_string<int> vals(valp);
    for (int i = 0; i < n; i++) {
        if (vals[i]) {
            for (int j = 0; j < k; j++)
                vals[i + j] ^= valq[j];
        }
    }
    for (int x : vals.substr(n, k - 1))
        cout << x;
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}