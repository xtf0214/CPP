#include <bits/stdc++.h>
using namespace std;
map<int, list<int>> mp;
int main()
{
    int n, m, s, cnt = 0;
    cin >> n >> m >> s;
    for (int i = 0, a, b; i < n; i++)
    {
        cin >> a >> b;
        if (b >= 90 && a >= 175)
            cnt++;
        else if (a >= 175)
            mp[a].push_back(b);
    }
    for (auto &i : mp)
    {
        i.second.sort();
        i.second.reverse();
    }
    for (int i = 0; i < m; i++)
        for (auto &j : mp)
            if (!j.second.empty())
            {
                cnt++;
                j.second.pop_front();
            }
    cout << cnt;
    return 0;
}