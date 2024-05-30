/**
 * @file    :   置换环
 * @author  :   Tanphoon
 * @date    :   2024/03/07 09:26
 * @version :   2024/03/07 09:26
 */
#include <bits/stdc++.h>
using namespace std;

// 置换环：数组排序元素间所需最小交换次数
int permutationCircle(const vector<int> &a) {
    int n = a.size(); // 1 <= a[i] <= n
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++)
        vp[i] = {a[i], i};
    sort(vp.begin(), vp.end());
    vector<int> vis(n);
    int loop = 0;
    for (int i = 0; i < n; i++) {
        int cycleSize = 0;
        for (int j = i; !vis[j]; j = vp[j].second) {
            vis[j] = 1;
            cycleSize++;
        }
        loop++;
    }
    return n - loop; 
}