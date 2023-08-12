/**
 * @file    :   C
 * @author  :   Tanphoon
 * @date    :   2023/08/12 23:26
 * @version :   2023/08/12 23:26
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#endif

void work(int n = 1) {
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);

    auto calc = [](const vector<int> &a) -> int {
        int s = 0, mx = 0, n = a.size();
        for (int i = 0; i < n; i++) {
            int k = a[i] * (i + 1);
            s += k;
            mx = max(mx, k);
        }
        return s - mx;
    };

    pair<int, vector<int>> ans = {0, {}};
    do {
        int s = calc(a);
        if (ans.first < s)
            ans = {s, a};
    } while (next_permutation(a.begin(), a.end()));
    cerr << ans.first << ' ' << ans.second;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for (int i = 2; i <= 10; i++)
        work(i);
    return 0;
}