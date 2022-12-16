#include <bits/stdc++.h>
using namespace std;

vector<int> primes, isPrime;
void euler(int n) {
    isPrime.assign(n, 1);
    isPrime[1] = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] < n; j++) {
            isPrime[i * primes[j]] = 0;
            if (i % primes[j] == 0)
                break;
        }
    }
}
bool solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int num = a[i];
        for (int p : primes) {
            if (p * p > num)
                break;
            if (num % p == 0) {
                while (num % p == 0)
                    num /= p;
                mp[p]++;
                if (mp[p] >= 2)
                    return true;
            }
        }
        if (num > 1)
            mp[num]++;
        if (mp[num] >= 2)
            return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    euler(31623);
    cin >> T;
    while (T--)
        puts(solve() ? "YES" : "NO");
    return 0;
}