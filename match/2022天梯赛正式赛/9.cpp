#include <bits/stdc++.h>
using namespace std;
list<int> ls;
stack<int> s;
vector<int> q;
    int n, m, k;
int get(int x)
{
    int t;
    if (s.empty())
    {
        t = ls.front();
        ls.pop_front();
        while (t > x)
        {
            if(s.size()==m)
                
            s.push(t);
            t = ls.front();
            ls.pop_front();
        }
    }
    else if (s.size() ==)
}
int main()
{

    int t;

    cin >> n >> m >> k;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        ls.push_back(x);
    }
    while (!ls.empty())
    {
        if (q.empty())
        {
            if (!s.empty())
            {
                t = s.top();
            }
            t = ls.front();
            ls.pop_front();
            q.push_back(t);
            continue;
        }
        if (q.size() < k)
        {
            int t = ls.front();
            ls.pop_front();
            while (t > q.front())
            {
                if (s.size() > m)
                {
                }
            }
            q.push_back(t);
        }
        for (int i : q)
            cout << i << " ";
        q.clear();
    }
}