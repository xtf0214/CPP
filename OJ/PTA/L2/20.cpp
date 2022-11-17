// 7-20 悄悄关注
#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> mp;
    set<string> s;
    int n, m;
    double sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string id;
        cin >> id;
        s.insert(id);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string id;
        int fans;
        cin >> id >> fans;
        sum += fans;
        mp[id] = fans;
    }
    sum /= m;
    bool flag = false;
    for (auto &[id, fans] : mp)
        if (fans > sum)
        {
            if (!s.count(id))
            {
                cout << id << endl;
                flag = true;
            }
        }
    if (!flag)
        cout << "Bing Mei You";
    return 0;
}