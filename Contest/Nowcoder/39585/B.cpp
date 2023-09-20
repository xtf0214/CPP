/** 
 * @file    :   B
 * @author  :   Tanphoon 
 * @date    :   2023/09/12 10:55
 * @version :   2023/09/12 10:55
 * @link    :   https://ac.nowcoder.com/acm/contest/39585/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, a, b, x;
    cin >> n >> a >> b >> x;
    string s;
    cin >> s;
    vector<int> ans;
    for (int i = 0, j = 0; i < n; ) {
        while (j < n && s[j] == s[i])
            j++;
        ans.push_back(s[i] == '1');
        i = j;
    }
    if (ans.front() == 1)
        ans.erase(ans.begin());
    if (ans.back() == 1)
        ans.pop_back();
    ll cnt1 = count(ans.begin(), ans.end(), 1);
    ll cnt0 = count(ans.begin(), ans.end(), 0);
    ll cost = min(cnt1 * a + b, cnt0 * b);
    if (x >= cost) {
        cout << "Yes\n";
        cout << x - cost << '\n';
    } else {
        cout << "No\n";
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}