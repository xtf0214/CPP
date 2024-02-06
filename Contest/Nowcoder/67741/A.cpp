/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2024/02/02 13:08
 * @version :   2024/02/02 13:08
 * @link    :   https://ac.nowcoder.com/acm/contest/67741/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ok1 = 0, ok2 = 0;
    int pos = 0;
    if ((pos = s.find('D', pos)) != -1) 
        if ((pos = s.find('F', pos)) != -1) 
            if ((pos = s.find('S', pos)) != -1)
                ok1 = 1;
    pos = 0;
    if ((pos = s.find('d', pos)) != -1)
        if ((pos = s.find('f', pos)) != -1)
            if ((pos = s.find('s', pos)) != -1)
                ok2 = 1;
    cout << ok1 << ' ' << ok2 << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}