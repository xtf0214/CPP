/**
 * @file    :   E
 * @author  :   Tanphoon
 * @date    :   2024/05/26 20:42
 * @version :   2024/05/26 20:42
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#else
#define debug(...) 0
#endif

bool isPrime(ll x) {
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
int calc(const vector<int> &p) {
    int n = p.size();
    for (int i = 0; i < n; i++) {
        if (isPrime(p[i] + (i + 1)) || isPrime(abs(p[i] - (i + 1))))
            return 0;
    }
    return 1;
};
void work(int n = 1) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    pair<int, vector<vector<int>>> ans = {1, {}};
    do {
        int s = calc(p);
        if (ans.first < s) {
            ans = {s, {p}};
        } else if (ans.first == s) {
            ans.second.push_back(p);
        }
    } while (next_permutation(p.begin(), p.end()));
    cerr << ans.first << ' ' << ans.second;
}
inline void solve() {
    int n;
    cin >> n;
    work(n);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}