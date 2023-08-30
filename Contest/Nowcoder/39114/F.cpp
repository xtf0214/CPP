/**
 * @file    :   F
 * @author  :   Tanphoon
 * @date    :   2023/08/29 15:54
 * @version :   2023/08/29 15:54
 * @link    :   https://ac.nowcoder.com/acm/contest/39114/F
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, s = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], s ^= a[i];
    for (int i = 0; i < a[0]; i++)
        for (int j = 1; j < n; j++) {
            int x = a[0] - i, y = a[j] + i;
            int t = s ^ a[0] ^ a[j] ^ x ^ y;
            if (t == 0) {
                cout << i << endl;
                return 0;
            }
        }
    cout << -1 << endl;
    return 0;
}