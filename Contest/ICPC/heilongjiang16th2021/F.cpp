/**
 * @file    :   F
 * @author  :   Tanphoon
 * @date    :   2024/04/23 00:33
 * @version :   2024/04/23 00:33
 * @link    :   https://codeforces.com/gym/103107/problem/F
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7 + 10;

vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    for (int i = 2; i <= n; i++) {
        if (!minp[i])
            minp[i] = i, primes.push_back(i);
        for (int j = 0; i * primes[j] <= n; j++) {
            minp[i * primes[j]] = primes[j];
            if (i % primes[j] == 0)
                break;
        }
    }
}
ll qmi(ll a, ll b) {
    ll res = 1;
    for (; b; a = a * a, b >>= 1)
        if (b & 1)
            res = res * a;
    return res;
}
ll fun(int i) {
    ll ans = 0;
    if (i == 1 || minp[i] == i)
        ans += 1;
    else {
        int k = 0, x = i;
        while (x % minp[i] == 0)
            x /= minp[i], k++;
        ans += x * qmi(minp[i], k / 2);
    }
    return ans;
}
signed main() {
    sieve(N);
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += fun(i);
    }
    cout << ans << '\n';
}