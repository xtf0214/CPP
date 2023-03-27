#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool isPrime(ll x) {
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return x != 0 && x != 1;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        ll x;
        cin >> x;
        puts(isPrime(x) ? "Yes" : "No");
    }
}