/**
 * @file    :   E
 * @author  :   Tanphoon
 * @date    :   2024/01/22 14:58
 * @version :   2024/01/22 14:58
 * @link    :   https://ac.nowcoder.com/acm/contest/74088/E
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    vector<int> q;
    for (int i = 1; i <= 1e6; i++) {
        if (!st.count(i) && q.size() < st.size())
            q.push_back(i);
        if (q.size() >= st.size())
            break;
    }
    map<int, int> mp;
    int bg = 0;
    for (int i = 0; i < n; i++) {
        if (!mp[a[i]]) {
            mp[a[i]] = q[bg++];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << mp[a[i]] << ' ';
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}