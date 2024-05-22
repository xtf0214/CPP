/**
 * @file    :   G
 * @author  :   Tanphoon
 * @date    :   2024/05/07 22:56
 * @version :   2024/05/07 22:56
 * @link    :   https://codeforces.com/gym/102803/problem/G
 */
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int x = n;
    vector<int> a;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                a.push_back(i);
                n /= i;
            }
        }
    }
    if (n != x && n != 1)
        a.push_back(n);
    sort(a.begin(), a.end());
    if (a.size() == 0)
        cout << "0\n";
    else if (a.size() == 2)
        cout << "-1\n";
    else {
        int m = a.size() - 1;
        cout << a[m] * a[m - 1] << '\n';
    }
}
int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}