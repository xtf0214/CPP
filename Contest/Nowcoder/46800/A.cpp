/**
 * @file    :   A   World Final? World Cup! (I)
 * @author  :   Tanphoon
 * @date    :   2023/01/16 13:06
 * @version :   2023/01/16 13:06
 * @link    :   https://ac.nowcoder.com/acm/contest/46800/A
 */
#include <bits/stdc++.h>
using namespace std;

// int solve() {
//     string s;
//     cin >> s;
//     int res[2]{0};
//     for (int i = 0; i < 10; i++) {
//         int team = i & 1;
//         res[team] += s[i] - '0';
//         if (team == 1) {
//             if (res[team ^ 1] + 4 - i / 2 < res[team] || res[team] + 4 - i / 2 < res[team ^ 1])
//                 return i + 1;
//         } else {
//             if (res[team ^ 1] + 4 - i / 2 + 1 < res[team] || res[team] + 4 - i / 2 < res[team ^ 1])
//                 return i + 1;
//         }
//     }
//     return -1;
// }
int solve() {
    string s;
    cin >> s;
    int res[2]{5, 5}, score[2]{0, 0};
    for (int i = 0; i < 10; i++) {
        int team = i & 1;
        res[team]--;
        score[team] += s[i] - '0';
        if (score[0] + res[0] < score[1] || score[1] + res[1] < score[0])
            return i + 1;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}