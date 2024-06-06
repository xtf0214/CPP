/**
 * @file    :   B
 * @author  :   Tanphoon
 * @date    :   2024/04/13 16:12
 * @version :   2024/04/13 16:12
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int N = 1e7;
    for (int i = 10; i <= N; i++) {
        if (i % (N / 100) == 0) {
            cout << i / (N / 100) << "%" << '\r';
        }
        vector<int> a;
        int x = i;
        while (x) {
            a.push_back(x % 10);
            x /= 10;
        }
        reverse(a.begin(), a.end());
        int n = a.size();
        int cur = accumulate(a.begin(), a.end(), 0LL);
        for (int j = 0; cur <= i; j++) {
            a.push_back(cur);
            cur += a.back() - a[j];
        }
        if (a.back() == i) {
            cout << i << '\n';
        }
        // 7913837
    }
}