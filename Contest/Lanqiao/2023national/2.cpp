#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 5;
const int MX = 23333333333333;
int st[N], p[N], cnt;

void eulor(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            p[cnt++] = i;
        for (int j = 0; i * p[j] <= n && j < cnt; j++) {
            st[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
}
signed main() {
    int n = sqrt(23333333333333) + 5; // 2415234
    eulor(n);
    int res = 0;
    for (int i = 0; i < cnt && p[i] <= MX / p[i]; i++) {
        for (int j = i + 1; j < cnt; j++) {
            __int128_t t = p[i] * p[i];
            t *= p[j] * p[j];
            if (t > MX)
                break;
            if (2333 <= t && t <= MX)
                res++;
        }
    }
    cout << res << endl;
    // 947293
}
