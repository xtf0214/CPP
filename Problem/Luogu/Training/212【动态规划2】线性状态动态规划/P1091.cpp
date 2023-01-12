/**
 * @file    :   P1091 [NOIP2004 提高组] 合唱队形
 * @author  :   Tanphoon
 * @date    :   2023/01/12 23:10
 * @version :   2023/01/12 23:10
 * @link    :   https://www.luogu.com.cn/problem/P1091
 */
#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    vector<int> a(n + 1), f(n + 1), g(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
    }
    for (int i = n; i >= 1; i--) {
        g[i] = 1;
        for (int j = n; j > i; j--)
            if (a[j] < a[i])
                g[i] = max(g[i], g[j] + 1);
    }
    for (int i = 1; i <= n; i++)
        s[i] = f[i] + g[i] - 1;
    cout << n - *max_element(s.begin(), s.end());
    return 0;
}