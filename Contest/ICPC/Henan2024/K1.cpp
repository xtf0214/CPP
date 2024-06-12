/**
 * @file    :   K 【根号分治】
 * @author  :   Tanphoon
 * @date    :   2024/06/12 14:11
 * @version :   2024/06/12 14:11
 * @link    :   https://ac.nowcoder.com/acm/contest/84773/K
 */
#include <bits/stdc++.h>
using namespace std;
inline void solve() {
    int n;
    cin >> n;
    vector<int> a1, a2;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x <= 1e4)
            a1.push_back(x);
        else
            a2.push_back(x);
    }
    int mx = 0;
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    a1.erase(unique(a1.begin(), a1.end()), a1.end());
    a2.erase(unique(a2.begin(), a2.end()), a2.end());
    for (int i = 0; i < a1.size(); i++)
        for (int j = i + 1; j < a1.size(); j++)
            mx = max(mx, a1[i] | a1[j]);
    for (int i = 0; i < a2.size(); i++)
        for (int j = i + 1; j < a2.size(); j++)
            mx = max(mx, a2[i] | a2[j]);
    for (int i = 0; i < (int)a1.size(); i++)
        for (int j = 0; j < (int)a2.size(); j++)
            mx = max(mx, a1[i] | a2[j]);
    cout << mx << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}