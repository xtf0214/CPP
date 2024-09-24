/**
 * @file    :   K
 * @author  :   Tanphoon
 * @date    :   2024/05/08 20:00
 * @version :   2024/05/08 20:00
 * @link    :   https://codeforces.com/gym/105143/problem/K
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

int Xor[N];
map<pair<int, int>, int> sg;

int mex(const vector<int> &v) {
    set<int> s(v.begin(), v.end());
    for (int i = 0;; i++)
        if (s.find(i) == s.end())
            return i;
}
int getSG(pair<int, int> rg) {
    if (rg.first == rg.second) {
        return 1;
    } else if ((Xor[rg.second] ^ Xor[rg.first - 1]) == 0) {
        return 0;
    } else if (sg.count(rg)) {
        return sg[rg];
    } else {
        sg[rg] = mex({getSG({rg.first, rg.second - 1}), getSG({rg.first + 1, rg.second})});
        return sg[rg];
    }
}
void init() {
    int n = 30;
    for (int i = 1; i <= n; i++)
        Xor[i] = Xor[i - 1] ^ i;
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = getSG({1, i});
        cout << i << ' ' << f[i] << '\n';
    }
}
void solve() {
    int n;
    cin >> n;
    int x = n % 4;
    if (x == 0 || x == 1)
        cout << "Fluttershy\n";
    else
        cout << "Pinkie Pie\n";
}
int main() {
    // init();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}