// 7-9 包装机
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
const int MAX = 100 + 5;
int main()
{
    stack<char> s;
    queue<char> q[MAX];
    string t;
    int n, m, s_max, op;
    cin >> n >> m >> s_max;
    cin.get();
    for (int i = 1; i <= n; i++)
    {
        getline(cin, t);
        for (char c : t)
            q[i].push(c);
    }
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
        else if (!q[op].empty())
        {
            if (s.size() >= s_max)
            {
                cout << s.top();
                s.pop();
            }
            s.push(q[op].front());
            q[op].pop();
        }
    }
    return 0;
}