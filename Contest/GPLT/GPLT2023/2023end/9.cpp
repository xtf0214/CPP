/** 
 * @file    :   L2-1 堆宝塔
 * @author  :   Tanphoon 
 * @date    :   2023/04/24 12:14
 * @version :   2023/04/24 12:14
 * @link    :   
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    queue<int> q;
    while (n--) {
        int x;
        cin >> x;
        q.push(x);
    }
    stack<int> A;
    stack<int> B;
    int mx = 0, ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (A.empty() || A.top() > u)
            A.push(u);
        else if (B.empty() || B.top() < u)
            B.push(u);
        else {
            ans++;
            mx = max(mx, int(A.size()));
            while (!A.empty())
                A.pop();
            while (!B.empty() && B.top() > u) {
                A.push(B.top());
                B.pop();
            }
            A.push(u);
        }
    }
    ans++;
    mx = max(mx, int(A.size()));
    if (!B.empty()) {
        ans++;
        mx = max(mx, int(B.size()));
    }
    cout << ans << " " << mx;
    return 0;
}
