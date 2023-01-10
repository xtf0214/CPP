// 7-3 银行业务队列简单模拟
#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000 + 5;
int main()
{
    queue<int> A, B;
    vector<int> ans;
    int x, n;
    cin >> n;
    for (int i = 0; i < n; i++)
        (cin >> x), x & 1 ? A.push(x) : B.push(x);
    while (!A.empty() || !B.empty())
    {
        if (!A.empty())
            ans.push_back(A.front()), A.pop();
        if (!A.empty())
            ans.push_back(A.front()), A.pop();
        if (!B.empty())
            ans.push_back(B.front()), B.pop();
    }
    for (int i : ans)
        cout << "_"[i == ans[0]] << i;
    return 0;
}