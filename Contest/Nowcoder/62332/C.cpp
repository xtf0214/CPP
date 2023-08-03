/**
 * @file    :   C
 * @author  :   Tanphoon
 * @date    :   2023/08/01 17:45
 * @version :   2023/08/01 17:45
 * @link    :   https://ac.nowcoder.com/acm/contest/62332/c
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

int p[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++)
            if (i % j == 0)
                p[i] += 1 + (j * j != i);
    }
    ll cnt = 0;
    for (int i = 1; i < n; i++) {
        cnt += p[i] * p[n - i];
    }
    cout << cnt << '\n';
    return 0;
}