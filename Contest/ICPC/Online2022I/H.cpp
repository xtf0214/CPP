/**
 * @file    :   H
 * @author  :   Tanphoon
 * @date    :   2024/01/10 19:23
 * @version :   2024/01/10 19:23
 */
#include <bits/stdc++.h>
using namespace std;
const int mod = 20220911;
inline void solve1() {
    vector<int> stk;
    stack<char> op;
    stk.push_back(0);
    string t = "0";
    string s;
    while (cin >> s && s != "fin") {
        if (s == "library") {
            t += "+1";
            stk.back() = (stk.back() + 1) % mod;
        } else if (s == "repeat") {
            stk.push_back(0);
            t += "+(0";
            op.push('+');
            op.push('(');
        } else if (s == "for") {
            cin >> s;
            int w = stoi(s);
            cin >> s;
            while (!op.empty()) {
                if (op.top() == '(') {
                    op.pop();
                    break;
                } else {
                    int y = stk.back();
                    stk.pop_back();
                    stk.back() = (stk.back() + y) % mod;
                    op.pop();
                }
            }
            t += ")*" + to_string(w);
            stk.back() = (stk.back() * w) % mod;
        }
    }
    while (!op.empty()) {
        int y = stk.back();
        stk.pop_back();
        stk.back() = (stk.back() + y) % mod;
        op.pop();
    }
    cout << stk.back() % mod << '\n';
}
inline void solve() {
    vector<string> sn;
    string s;
    while (cin >> s && s != "fin")
        if (s != "arithmetic")
            sn.push_back(s);
    int n = sn.size();
    stack<int> stk;
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        if (sn[i] == "repeat") {
            stk.push(i);
        } else if (sn[i] == "for") {
            pos[stk.top()] = i;
            stk.pop();
        }
    }
    function<int(int, int)> f = [&](int l, int r) -> int {
        int res = 0;
        for (int i = l; i <= r; i++) {
            if (sn[i] == "library") {
                res = (res + 1) % mod;
            } else if (sn[i] == "repeat") {
                int w = stoi(sn[pos[i] + 1]);
                res = (res + f(i + 1, pos[i] - 1) * w % mod) % mod;
                i = pos[i] + 2;
            }
        }
        return res;
    };
    cout << f(0, n - 1) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve1();
    return 0;
}