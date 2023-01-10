// 7-94 出栈序列的合法性
#include <bits/stdc++.h>
using namespace std;
int m, n, k;
bool check(int a[])
{
    stack<int> s;
    for (int x = 1, top = 0; x <= n; x++)
    {
        s.push(x);
        if (s.size() > m)
            return false;
        while (!s.empty() && s.top() == a[top])
            s.pop(), top++;
    }
    return s.empty();
}
int main()
{

    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << (check(a) ? "YES" : "NO") << endl;
    }
}
