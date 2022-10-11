#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(v) v.begin(), v.end()

int main()
{
    int n;
    string s;
    vi q(1, 1);
    cin >> s;
    n = s.size();
    if (n != 1)
        q.push_back(n);
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            q.push_back(i);
            if (i != n / i)
                q.push_back(n / i);
        }
    sort(all(q));
    for (int len : q)
    {
        bool flag = true;
        for (int i = len; i < n; i += len)
            if (s.find(s.substr(0, len), i) == -1)
            {
                flag = false;
                break;
            }
        if(flag)
        {
            cout << len;
            return 0;
        }
    }
    return 0;
}