/**
 * @file    :   计算因数个数
 * @author  :   Tanphoon
 * @date    :   2024/06/30 17:12
 * @version :   2024/06/30 17:12
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include <DEBUG.h>
#else
#define debug(...) 0
#endif

// factor cnt
vector<int> rec1(int n) {
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            cnt[j]++;
    return cnt;
}
// factor cnt
vector<int> rec2(int n) {
    vector<int> cnt(n + 1, 1), st(n + 1);
    for (int i = 2; i <= n; i++)
        if (!st[i])
            for (int j = 1; j * i <= n; j++)
                cnt[i * j] += cnt[j], st[i * j] = 1;
    return cnt;
}
// all factor
vector<basic_string<int>> rec3(int n) {
    vector<basic_string<int>> cnt(n + 1);
    for (int i = 1; i <= n; i++)
        cnt[i] = {i};
    vector<int> st(n + 1);
    for (int i = 2; i <= n; i++)
        if (!st[i])
            for (int j = 1; j * i <= n; j++)
                cnt[i * j] += cnt[j], st[i * j] = 1;
    return cnt;
}
// all prime factor
vector<basic_string<int>> rec4(int n) {
    vector<basic_string<int>> cnt(n + 1);
    vector<int> st(n + 1);
    for (int i = 2; i <= n; i++)
        if (!st[i])
            for (int j = 1; j * i <= n; j++)
                cnt[i * j] += i, st[i * j] = 1;
    return cnt;
}
// min prime factor
vector<int> rec5(int n) {
    vector<int> minp, primes;
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
    return minp;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    debugln(rec1(20));
    debugln(rec2(20));
    debugln(rec3(20));
    debugln(rec4(20));
    debugln(rec5(20));
    return 0;
}