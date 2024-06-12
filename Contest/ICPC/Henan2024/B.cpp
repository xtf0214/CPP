/** 
 * @file    :   B
 * @author  :   Tanphoon
 * @date    :   2024/06/12 17:34
 * @version :   2024/06/12 17:34
 * @link    :   https://ac.nowcoder.com/acm/contest/84773/B
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    string s;
    double x;
    cin >> s >> x;
    vector<int> pos(s.size());
    stack<int> sta;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            sta.push(i);
        } else if (s[i] == ')') {
            pos[sta.top()] = i;
            sta.pop();
        }
    }
    function<double(int, int, double)> f = [&](int l, int r, double x) -> double {
        char op;
        double ans;
        if (s[l] == 'l') {
            int r2 = pos[l + 2];
            ans = log(f(l + 3, r2 - 1, x));
            if (r2 == r) {
                return ans;
            } else {
                op = s[r2 + 1];
                l = r2 + 2;
            }
        } else {
            ans = x;
            if (l == r) {
                return ans;
            } else {
                op = s[l + 1];
                l = l + 2;
            }
        }
        if (op == '+')
            return ans + f(l, r, x);
        else
            return ans - f(l, r, x);
    };
    cout << fixed << setprecision(2)
         << (f(0, s.size() - 1, x) - f(0, s.size() - 1, x - 1e-10)) / 1e-10 << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}