/**
 * @file    :   F
 * @author  :   Tanphoon
 * @date    :   2024/05/08 20:00
 * @version :   2024/05/08 20:00
 * @link    :   https://codeforces.com/gym/105143/problem/F
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 5;

#ifdef _DEBUG
#define INTERACT
#include "DEBUG.h"
#else
#define debug(...) 0
#endif

#ifdef INTERACT
vector<vector<int>> a = {
    {0, 0, 0, 0},
    {0, 1, 2, 4},
    {0, 3, 4, 8},
    {0, 6, 7, 9},
};
int query(int i, int j, int x) { return a[i][j] <= x; }
#else
int query(int i, int j, int x) {
    cout << "? " << i << ' ' << j << ' ' << x << endl;
    int ans;
    cin >> ans;
    return ans;
}
#endif

int main() {
    int n, k;
    cin >> n >> k;
    int l = 0, r = n * n + 1;
    auto check = [&](int x) {
        int sum = 0; // 矩阵中>=x的个数
        // for (int i = 1, j = n; i <= n; i++) {
        //     while (j >= 1 && !query(i, j, x))
        //         j--;
        //     sum += n - j;
        // }
        for (int i = n, j = 1; i >= 1; i--) {
            while (j <= n && query(i, j, x))
                j++;
            sum += n - j + 1;
        }
        return sum;
    };
    while (r - l > 1) {
        int mid = (l + r) / 2;
        (check(mid) < k) ? r = mid : l = mid;
    }
    // 二分答案x，查询(矩阵中>=x的个数)刚好=x，此时x就是第x大
    cout << "! " << r << endl;
    return 0;
}
