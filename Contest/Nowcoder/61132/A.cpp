#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#endif
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int phi[N], prime[N], cnt;
bool isPrime[N];
ll s[N];

void init_phi(int n) {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < cnt && ll(i) * prime[j] <= n; j++) {
            isPrime[i * prime[j]] = false;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            }
        }
    }
    print(vector<int>(phi, phi + 10));
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + phi[i];
}

ll H(ll n) {
    ll res = 0;
    cerr << n << '\n';
    for (int l = 1, r; l <= n; l = r + 1) 
    {
        int d = n / l;
        r = n / d;
        cerr << l << ' ' << r << '\n';
        res += (s[r] - s[l - 1]) * d;
    }
    return res;
}
int main() {
    init_phi(N);
    ll k;
    cin >> k;
    ll ans = 0;
    for (ll i = 1; i <= k; i++) {
        cout << H(i) << '\n';
        ans = (ans + H(i)) % mod;
    }
    cerr << '\n';
    cout << ans << '\n';
}

// 3

// 3 1 1