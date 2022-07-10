#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int a[MAX];
int main()
{
    int n, m, k, r = 0, x;
    cin >> n >> m;
    queue<int> q;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);
    }
    for (int i = 0; i < ceil(n / m); i++)
    {
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            s.push(x);
        }
        for (int i = 0; i < m; i++)
        {
            a[q.front()] = s.top();
            q.pop();
            s.pop();
        }
    }
    cin >> k;
    while (k--)
    {
        cin >> x;
        a[x] ? printf("%d\n", a[x]) : printf("Wrong Number\n");
    }
    return 0;
}