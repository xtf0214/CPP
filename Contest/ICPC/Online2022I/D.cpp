/**
 * @file    :   D
 * @author  :   Tanphoon
 * @date    :   2024/01/10 15:13
 * @version :   2024/01/10 15:13
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> aa{2};
inline void solve() {
    int l, r;
    cin >> l >> r;
    int val = *lower_bound(aa.begin(), aa.end(), l);
    if (val <= r) {
        cout << val << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n = 8;
    for (int i = 3; i < n; i++) {              // i leftmost 1
        for (int j = 2; j <= i - j + 1; j++) { // j rightmost 1
            vector<int> a(n);
            a[i] = a[j] = 1;
            fill_n(a.begin() + j + 1, j - 2, 1);
            do {
                int sum = 0;
                for (int i = 0; i < n; i++)
                    sum += a[i] << i;
                aa.push_back(sum);
            } while (prev_permutation(a.begin() + j + 1, a.begin() + i));
        }
    }
    sort(aa.begin(), aa.end());
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}