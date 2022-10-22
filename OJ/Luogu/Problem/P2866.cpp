// P2866 [USACO06NOV]Bad Hair Day S
// https://www.luogu.com.cn/problem/P2866
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, h;
    long long ans = 0;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        while (!s.empty() && h >= s.top())
            s.pop();
        ans += s.size();
        s.push(h);
    }
    cout << ans;
    return 0;
} 