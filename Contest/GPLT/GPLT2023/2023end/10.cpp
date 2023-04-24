/** 
 * @file    :   L2-2 天梯赛的赛场安排
 * @author  :   Tanphoon 
 * @date    :   2023/04/24 12:14
 * @version :   2023/04/24 12:14
 * @link    :   
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c, cnt = 0;
    cin >> n >> c;
    priority_queue<int> q;
    while (n--) {
        string s;
        int x;
        cin >> s >> x;
        // 一个学校要么包揽整个考场，要么跟别的学校分考场
        cout << s << " " << ceil(1.0 * x / c) << endl;
        cnt += x / c;
        if (x % c != 0)
            q.push(x % c);
    }
    vector<int> a;
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        bool ok = false;
        // 寻找剩余空位数 ≥ n 的编号最小的赛场，将队员安排进去
        for (int i = 0; i < a.size(); i++)
            if (a[i] + u <= c) {
                ok = true;
                a[i] += u;
                break;
            }
        // 找不到任何非空的、剩余空位数 ≥ n 的赛场了，则新开一个赛场，将队员安排进去
        if (!ok)
            a.push_back(u);
    }
    cout << cnt + a.size() << endl;
    return 0;
}
