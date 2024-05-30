/**
 * @file    :   I
 * @author  :   Tanphoon
 * @date    :   2024/05/29 02:15
 * @version :   2024/05/29 02:15
 * @link    :   https://codeforces.com/gym/105184/problem/I
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a[5];
    scanf("%d.%d.%d.%d/%d", &a[0], &a[1], &a[2], &a[3], &a[4]);
    string s;
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            s += char('0' + a[i] % 2);
            a[i] /= 2;
        }
    }
    reverse(s.begin(), s.end());
    s = s.substr(0, a[4]);
    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
        string _s;
        for (int i = 3; i >= 0; i--) {
            for (int j = 0; j < 8; j++) {
                _s += char('0' + a[i] % 2);
                a[i] /= 2;
            }
        }
        reverse(_s.begin(), _s.end());
        _s = _s.substr(0, a[4]);
        if (_s == s)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}