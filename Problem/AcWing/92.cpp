/**
 * @file    :   92.递归实现指数型枚举
 * @author  :   Tanphoon
 * @date    :   2023/02/12 23:22
 * @version :   2023/02/12 23:22
 * @link    :   https://www.acwing.com/problem/content/94/
 */
#include <bits/stdc++.h>
using namespace std;
#define bitGet(x, i) ((x >> i) & 1)
#define bitSet0(x, i) (x & ~(1 << k))
#define bitSet1(x, i) (x | (1 << i))

// vector<int> vis;
// void dfs(int k, int n) { // dfs(0, n)
//     if (k == n) {
//         for (int i = 0; i < n; i++)
//             if (vis[i])
//                 cout << i + 1 << " ";
//         cout << endl;
//         return;
//     }
//     vis[k] = false;
//     dfs(k + 1, n);
//     vis[k] = true;
//     dfs(k + 1, n);
// }
void dfs(int k, int S, int n) { // dfs(0, 0, n)
    if (k == n) {
        for (int i = 0; i < n; i++)
            if (bitGet(S, i))
                cout << i + 1 << " ";
        cout << endl;
        return;
    }
    dfs(k + 1, bitSet0(S, k), n);
    dfs(k + 1, bitSet1(S, k), n);
}
// void solve(int n) {
//     for (int S = 0; S < (1 << n) - 1; S++) {
//         for (int i = 0; i < n; i++)
//             if (bitGet(S, i))
//                 cout << i + 1 << " ";
//         cout << endl;
//     }
// }
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    // vis.resize(n);
    // puts("\033[0;31msolve1\033[0m");
    // dfs(0, n);

    // puts("\033[0;31msolve2\033[0m");
    dfs(0, 0, n);

    // puts("\033[0;31msolve3\033[0m");
    // solve(n);
    return 0;
}