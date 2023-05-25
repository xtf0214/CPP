/**
 * @file    :   P1757 通天之分组背包
 * @author  :   Tanphoon
 * @date    :   2023/05/25 22:21
 * @version :   2023/05/25 22:21
 * @link    :   https://www.luogu.com.cn/problem/solution/P1757
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m, ts; // 物品个数；背包容量；物品组数
int w[N], v[N], f[N]; 
vector<int> t[105]; // 第i组的物品编号

int main() {
    cin >> m >> n;
    for (int i = 1, k; i <= n; i++) {
        cin >> w[i] >> v[i] >> k;
        ts = max(ts, k);
        t[k].push_back(i);
    }
    for (int k = 1; k <= ts; k++)
        for (int j = m; j >= 0; j--)
            for (int i : t[k])
                if (j >= w[i])
                    f[j] = max(f[j], f[j - w[i]] + v[i]);
    cout << f[m] << endl;
    return 0;
}