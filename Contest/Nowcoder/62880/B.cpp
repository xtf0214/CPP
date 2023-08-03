/** 
 * @file    :   B
 * @author  :   Tanphoon 
 * @date    :   2023/08/02 13:08
 * @version :   2023/08/02 13:08
 * @link    :   https://ac.nowcoder.com/acm/contest/62880/B
 */
#include <bits/stdc++.h>
using namespace std;
uint64_t a[25];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = 0;
    for (int S = 1; S < (1 << n); S++) {
        uint64_t t = ~0;
        for (int i = 0; i < n; i++) 
            if (S >> i & 1) {
                t &= a[i];
            }
        if (__builtin_popcount(t) == k)
            cnt++;
    } 
    cout << cnt << '\n';
    return 0;
}