/**
 * @file    :   E
 * @author  :   Tanphoon
 * @date    :   2024/04/13 16:12
 * @version :   2024/04/13 16:12
 * @link    :   https://www.dotcpp.com/oj/train/1118/
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    double p;
    cin >> n >> p;
    double min = 1e9;
    int ans = 0;
    for (int k = 1; k <= n; ++k) {
        if (n % k != 0)
            continue;
        if (min >= n / k + n * p * k) {
            min = n / k + n * p * k;
            ans = k;
        }
    }
    cout << ans << '\n';
    return 0;
}