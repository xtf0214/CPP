/**
 * @file    :   M 二手物品回收
 * @author  :   Tanphoon
 * @date    :   2023/05/25 22:45
 * @version :   2023/05/25 22:45
 * @link    :   https://ac.nowcoder.com/acm/contest/58860/M
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e3 + 5;

int n, m, ts;
i64 f[N];     // f[i]: 出售i个物品最多能赚的钱
i64 pr[N][N]; // pr[i][j]: 第i个商家回收j个物品的价格
int p[N];     // 快递费
vector<int> t[N];

int main() {
    cin >> n >> ts >> m;
    for (int k = 1; k <= ts; k++)
        cin >> p[k];
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        t[b].push_back(a);
    }
    for (int k = 1; k <= ts; k++) {
        sort(t[k].begin(), t[k].end(), greater<int>());
        pr[k][0] = -p[k];
        for (int i = 1; i <= t[k].size(); i++)
            pr[k][i] = pr[k][i - 1] + t[k][i - 1];
    }
    fill(f + 1, f + 1 + m, -1e8);
    for (int k = 1; k <= ts; k++)
        for (int j = m; j >= 0; j--)
            for (int i = 1; i <= t[k].size(); i++)
                if (j >= i)
                    f[j] = max(f[j], f[j - i] + pr[k][i]);
    cout << f[m];
    return 0;
}
