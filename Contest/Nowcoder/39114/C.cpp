/**
 * @file    :   C
 * @author  :   Tanphoon
 * @date    :   2023/08/29 15:53
 * @version :   2023/08/29 15:53
 * @link    :   https://ac.nowcoder.com/acm/contest/39114
 */
#include <bits/stdc++.h>
using namespace std;

pair<int, int> key[30]{{2, 1}, {3, 6}, {3, 4}, {2, 3}, {1, 3}, {2, 4}, {2, 5},  {2, 6}, {1, 8},
                       {2, 7}, {2, 8}, {2, 9}, {3, 8}, {3, 7}, {1, 9}, {1, 10}, {1, 1}, {1, 4},
                       {2, 2}, {1, 5}, {1, 7}, {3, 5}, {1, 2}, {3, 3}, {1, 6},  {3, 2}};
void solve() {
    string s;
    cin >> s;
    for (auto &i : s) {
        if ('A' <= i && i <= 'Z')
            cout << 3 << " " << 1 << " " << key[i - 'A'].first << " " << key[i - 'A'].second;
        else
            cout << key[i - 'a'].first << " " << key[i - 'a'].second;
        cout << endl;
    }
}
int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}