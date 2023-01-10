// 7-7 前世档案
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int ans = 1;
        string s;
        cin >> s;
        for (char ch : s)
        {
            if (ch == 'y')
                ans = ans * 2 - 1;
            else
                ans = ans * 2;
        }
        cout << ans << endl;
    }
    return 0;
}