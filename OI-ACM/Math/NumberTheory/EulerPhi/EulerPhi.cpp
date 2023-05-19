#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
int phi[N], prime[N], cnt;
bool isPrime[N];
int euler_phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            res = res / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        res = res / n * (n - 1);
    return res;
}   
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
}