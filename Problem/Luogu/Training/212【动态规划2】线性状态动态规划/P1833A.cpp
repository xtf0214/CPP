/**
 * @file    :   P1833 樱花
 * @author  :   Tanphoon
 * @date    :   2023/01/14 20:43
 * @version :   2023/01/14 20:43
 * @link    :   https://www.luogu.com.cn/problem/P1833
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int hh1, mm1, hh2, mm2, W, n;
    scanf("%d:%d %d:%d %d", &hh1, &mm1, &hh2, &mm2, &n);
    W = (hh2 - hh1) * 60 + mm2 - mm1;
    vector<int> w(n + 1), v(n + 1), c(n + 1);
    vector<int> f(W + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i] >> c[i];
    for (int i = 1; i <= n; i++) {
        if (c[i])
            for (int k = 1; k <= c[i]; k++)
                for (int j = W; j >= w[i]; j--)
                    f[j] = max(f[j], f[j - w[i]] + v[i]);
        else
            for (int j = w[i]; j <= W; j++)
                f[j] = max(f[j], f[j - w[i]] + v[i]);
    }
    cout << f[W];
    return 0;
}