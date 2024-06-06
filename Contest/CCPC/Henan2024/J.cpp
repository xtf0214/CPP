/**
 * @file    :   J
 * @author  :   Tanphoon
 * @date    :   2024/05/15 13:13
 * @version :   2024/05/15 13:13
 * @link    :   https://codeforces.com/gym/105158/problem/J
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6;
map<string, int> mp;
vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; i * primes[j] <= n; j++) {
            minp[i * primes[j]] = i;
            if (i % primes[j] == 0)
                break;
        }
    }
}
string getHash(int x) {
    int cnt[10] = {};
    for (int i : to_string(x))
        cnt[i - '0']++;
    string s;
    for (int i = 0; i < 10; i++)
        s += cnt[i] + '0';
    return s;
}
void init() {
    sieve(N);
    for (int i = 1; i < N; i++) {
        if (minp[i] != i) {
            string x = getHash(i);
            if (!mp.count(x))
                mp[x] = i;
        }
    }
}
void solve() {
    int x;
    cin >> x;
    string s = getHash(x);
    if (mp.count(s)) {
        cout << mp[s] << '\n';
    } else {
        cout << -1 << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    init();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}