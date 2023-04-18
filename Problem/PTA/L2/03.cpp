/**
 * @file    :   7-3 银行业务队列简单模拟
 * @author  :   Tanphoon
 * @date    :   2023/04/17 16:50
 * @version :   2023/04/17 16:50
 * @link    :   https://pintia.cn/problem-sets/1647005933907861504/problems/1647006411324506112
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    queue<int> A, B;
    vector<int> ans;
    int x, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x & 1)
            A.push(x);
        else
            B.push(x);
    }
    while (!A.empty() || !B.empty()) {
        if (!A.empty()) {
            ans.push_back(A.front());
            A.pop();
        }
        if (!A.empty()) {
            ans.push_back(A.front());
            A.pop();
        }
        if (!B.empty()) {
            ans.push_back(B.front());
            B.pop();
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    return 0;
}