#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    string ss[8] = {"11111111", "10000001", "10111101", "10111101",
                    "10111101", "10111101", "10000001", "11111111"};
    string s[1005];
    vector<pair<int, int>> ans;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int pos = 0; pos < m - 7; pos++)
    {
        int i = 0, j = 0;
        while (i < n)
        {
            while (i < n && j < 8)
                if (s[i].substr(pos, 8) == ss[j])
                    i++, j++;
                else
                    i = i - j + 1, j = 0;
            if (j >= 8)
            {
                ans.push_back({i - j, pos});
                j = 0;
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i.first << " " << i.second << endl;
    return 0;
}