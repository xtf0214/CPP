#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5, mod = 1e9 + 7;

int phi[N], prime[N], cnt;
bool isPrime[N];
ll s[N]; // pr[phi]

void init_phi(int n) {
    memset(isPrime, true, sizeof(isPrime));
    cnt = 0;
    isPrime[1] = false;
    phi[1] = 1;
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
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + phi[i];
}

ll H(ll n) {
    ll res = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
        int d = n / l;
        r = n / d;
        res += (s[r] - s[l - 1]) * d;
    }
    return res;
}
int main() {
    init_phi(1e6);
    ll k;
    cin >> k;
    for (ll i = 1; i <= k; i++) {
        cout << i << " " << H(i) << " " << i * (i + 1) / 2 << '\n';
    }
}