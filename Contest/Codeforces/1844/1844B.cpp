/**
 * @file    :   1844B
 * @author  :   Tanphoon
 * @date    :   2023/07/11 22:43
 * @version :   2023/07/11 22:43
 * @link    :   https://codeforces.com/contest/1844/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#endif

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return x > 1;
}

int b[10] = {0, 1, 2, 3, 6, 8, 12, 15, 19, 24};

void solve1(int n = 1) {
    vector<int> a(n);
    pair<int, vector<int>> ans;
    iota(a.begin(), a.end(), 1);
    auto mex = [&](vector<int> &S) { return find(S.begin() + 1, S.end(), 0) - S.begin(); };
    auto check = [&](const vector<int> &a) {
        int cnt = 0, n = a.size();
        vector<int> S(n + 2);
        for (int i = 0; i < n; i++) {
            fill(S.begin(), S.end(), 0);
            for (int j = i; j < n; j++) {
                S[a[j]] = 1;
                int t = mex(S);
                if (isPrime(t)) {
                    cnt++;
                }
            }
        };
        return cnt;
    };
    do {
        int cnt = check(a);
        if (cnt > ans.first)
            ans = {cnt, a};
    } while (next_permutation(a.begin(), a.end()));
    cout << ans.first << '\n';
    print(ans.second);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int l = 0, r = n - 1;
    for (int i = 2; i < n; i += 2) {
        a[l++] = i;
        a[r--] = i + 1;
    }
    if (l == r)
        a[l] = 1;
    else {
        a[l] = 1;
        a[r] = n;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}