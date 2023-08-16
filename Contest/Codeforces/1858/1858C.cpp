/**
 * @file    :   1858C
 * @author  :   Tanphoon
 * @date    :   2023/08/15 22:56
 * @version :   2023/08/15 22:56
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#endif
const int N = 1e6 + 5;

// void work(int n = 1) {
//     vector<int> a(n);
//     iota(a.begin(), a.end(), 1);
//     auto calc = [](const vector<int> &a) -> int {
//         int s = 0, mx = 0, n = a.size();
//         set<int> st;
//         for (int i = 0; i < n; i++) {
//             st.insert(gcd(a[i], a[(i + 1) % n]));
//         }
//         return st.size();
//     };
//     pair<int, vector<vector<int>>> ans = {0, {}};
//     do {
//         int s = calc(a);
//         if (ans.first < s)
//             ans = {s, {a}};
//         else if (ans.first == s)
//             ans.second.push_back(a);
//     } while (next_permutation(a.begin(), a.end()));
//     cerr << ans.first << ' ' << ans.second;
// }

void solve() {
    int n;
    cin >> n;
    vector<int> b(n + 1, 0);
    vector<int> a{1};
    for (int i = 2; i <= n; i++)
        for (int j = i; j <= n; j*=2)
            if (!b[j]) {
                a.push_back(j);
                b[j] = 1;
            }
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    // for (int i = 2; i <= 6; i++)
    //     work(i);
    cin >> T;
    while (T--)
        solve();
    return 0;
}