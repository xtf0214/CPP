#include <iostream>
#include <map>
using namespace std;
int main()
{
    int T, n, k;
    int u, v;
    map<int, pair<int, int>> mp;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        mp.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> u;
            if (mp.find(u) == mp.end())
                mp[u] = {i, i};
            else
            {
                auto t = mp.find(u);
                if (i < t->second.first)
                    t->second.first = i;
                if (i > t->second.second)
                    t->second.second = i;
            }
        }
        // for (auto i : mp)
        //     cout << i.first << " "
        //          << "[" << i.second.first << "," << i.second.second << "]\n";
        while (k--)
        {
            cin >> u >> v;
            if (mp.find(u) == mp.end() || mp.find(v) == mp.end())
            {
                cout << "NO" << endl;
                continue;
            }
            if (mp[u].first < mp[v].second)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}