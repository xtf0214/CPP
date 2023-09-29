/** 
 * @file    :   B
 * @author  :   Tanphoon 
 * @date    :   2023/09/29 11:28
 * @version :   2023/09/29 11:28
 * @link    :   https://ac.nowcoder.com/acm/contest/47681/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    int mx = 0;
    vector<double> bas = {0, 2, 1, 1, 1.5, 2, 1, 1, 1};
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mx = max(mx, int(y * bas[x]));
    }
    cout << mx << '\n';
}