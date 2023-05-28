/** 
 * @file    :   Codeforces Round 875 (Div. 2) B
 * @author  :   Tanphoon 
 * @date    :   2023/05/29 03:10
 * @version :   2023/05/29 03:10
 * @link    :   https://codeforces.com/contest/1831/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    // auto work = [n](vector<int> &a) {
    //     map<int, int> mp;
    //     int cnt = 1;
    //     for (int i = 1; i < n; i++) {
    //         if (a[i] != a[i - 1]) {
    //             mp[a[i - 1]] = max(mp[a[i - 1]], cnt);
    //             cnt = 1;
    //         } else
    //             cnt++;
    //     }
    //     mp[a.back()] = max(mp[a.back()], cnt);
    //     return mp;
    // };
    auto work = [n](vector<int> &a) {
        map<int, int> mp;
        for (int i = 0, j = 0; i < n;) {
            while (j < n && a[j] == a[i])
                j++;
            mp[a[i]] = max(mp[a[i]], j - i);
            i = j;
        }
        return mp;
    };
    map<int, int> mpa(work(a)), mpb(work(b));
    map<int, int> mp;
    for (auto &[k, v] : mpa)
        mp[k] += v;
    for (auto &[k, v] : mpb)
        mp[k] += v;
    int mx = 0;
    for (auto &[k, v] : mp)
        mx = max(mx, v);
    cout << mx << endl;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}