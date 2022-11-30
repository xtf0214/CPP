// P1090 合并果子
// https://www.luogu.com.cn/problem/P1090
#include <bits/stdc++.h>
using namespace std;
signed main()
{
    priority_queue<int, vector<int>, greater<int>> q;
    int n, x, y, ans = 0, cost;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x, q.push(x);
    while (q.size() > 1)
    {
        x = q.top(), q.pop();
        y = q.top(), q.pop();
        q.push(x + y);
        ans += x + y;
    }
    cout << ans << endl;
    return 0;
}