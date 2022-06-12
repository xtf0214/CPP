#include <iostream>
#include <stack>
using namespace std;
string a[105];
int top[105]; //可以考虑使用队列优化
int n, m, s_max, op;
int main()
{
    stack<char> s;
    cin >> n >> m >> s_max;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (cin >> op && op != -1)
    {
        if (op == 0)
        {
            if (!s.empty())
            {
                cout << s.top();
                s.pop();
            }
        }
        else
        {
            if (top[op] < a[op].size())
            {
                if (s.size() >= s_max)
                {
                    cout << s.top();
                    s.pop();
                }
                s.push(a[op][top[op]++]);
            }
        }
    }
    return 0;
}