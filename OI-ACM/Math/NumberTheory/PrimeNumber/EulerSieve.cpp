#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 5;
bool isPrime[N];
int st[N];
int prime[N], cnt = 0;
void eulerSieve(int n) {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i])
            prime[cnt++] = i;
        for (int j = 0; j < cnt && (long long)i * prime[j] <= n; j++) {
            isPrime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void minPrimeFactor(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            st[i] = i, prime[cnt++] = i;
        for (int j = 0; j < cnt && (long long)i * prime[j] <= n; j++) {
            st[i * prime[j]] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main() {
    int n;
    cin >> n;
    eulerSieve(n);
    for (int i = 0; i < cnt; i++)
        cout << prime[i] << " ";
    return 0;
}
