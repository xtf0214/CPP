/**
 * @file    :   E
 * @author  :   Tanphoon
 * @date    :   2023/10/14 20:43
 * @version :   2023/10/14 20:43
 * @link    :   https://www.lanqiao.cn/problems/5132/learning/?contest_id=144
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(string s) {
    int n = s.size();
    vector<int> pi(n + 1);
    for (int i = 1; i < n; i++) {
        int j = pi[i];
        while (j && s[i] != s[j])
            j = pi[j];
        if (s[i] == s[j])
            j++;
        pi[i + 1] = j;
    }
    return pi;
}
vector<int> kmp(string s, string p) {
    string cur = p + '#' + s;
    int n = s.size(), m = p.size();
    vector<int> pos, pi = prefix(cur);
    // cur: [0, m-1]=p, [m]="#", [m+1, m+n]=s
    for (int i = m + 1; i <= n + m; i++)
        if (pi[i + 1] == m)
            pos.push_back(i - 2 * m);
    return pos;
}

void solve() {
    int n, m;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s += s;
    m = n;
    for (int i = 0; i < m; i++) {
        if (islower(t[i]))
            t[i] = char(toupper(t[i]));
        else
            t[i] = char(tolower(t[i]));
    }
    vector<int> pos = kmp(s, t);
    if (pos.empty()) {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
        int p = pos[0];
        cout << min(p, n - p) << '\n';
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    while (T--)
        solve();
    return 0;
}