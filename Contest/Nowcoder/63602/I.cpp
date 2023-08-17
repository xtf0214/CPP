/**
 * @file    :   I
 * @author  :   Tanphoon
 * @date    :   2023/08/16 13:35
 * @version :   2023/08/16 13:35
 * @link    :   https://ac.nowcoder.com/acm/contest/63602/I
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    uint32_t a;
    cin >> a;
    uint32_t x[4];
    for (int i = 0; i < 4; i++) {
        x[i] = a & 0b11111111;
        a >>= 8;
    }
    sort(x, x + 4);
    a = 0;
    for (int i = 3; i >= 0; i--) {
        a |= x[i];
        if (i)
            a <<= 8;
    }
    cout << a;
    return 0;
}