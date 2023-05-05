/**
 * @file    :   Codeforces Round 869 (Div. 2) B. Indivisible
 * @author  :   Tanphoon
 * @date    :   2023/05/04 21:12
 * @version :   2023/05/04 21:12
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    if (n % 2 == 1 && n != 1) {
        cout << -1 << endl;
    } else if (n == 1) {
        cout << 1 << endl;
    } else {
        for (int i = 0; i < n; i++)
            cout << (i ^ 1) + 1 << " ";
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}