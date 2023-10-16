/** 
 * @file    :   Gas_station
 * @author  :   Tanphoon 
 * @date    :   2023/10/09 20:13
 * @version :   2023/10/09 20:13
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    int cnt = 0;          // cnt:加油次数
    vector<int> ans;      // ans:记录在哪个站加油
    cin >> n >> k;        // n:加满油行驶距离 k:加油站数
    int res = n;          // res:剩余油量能达到的最远位置
    vector<int> a(k + 2); // a:每个加油站的位置
    for (int i = 1; i <= k + 1; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= k + 1; i++) {
        if (res < a[i]) {       // 剩余油量无法达到当前加油站
            res = a[i - 1] + n; // 选择前一个加油站加油
            if (res >= a[i]) {  // 加了油能达到当前位置
                ans.push_back(i - 1);
                cnt++;
            } else { // 加了油也不能达到当前位置
                printf("无法达到第%d个加油站\n", i);
                return 0;
            }
        }
    }
    cout << "最少加油次数：" << cnt << '\n';
    cout << "经过的加油站为：";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ", ";
    return 0;
}