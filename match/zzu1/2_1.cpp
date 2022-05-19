#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> ans;
int BF(string s[], int l, int n, string ss[], int m, int pos)
{
    int j = 0;
    while (pos < n && j < m)
        if (s[pos].substr(l, m) == ss[j])
            pos++, j++;
        else
            pos = pos - j + 1, j = 0;
    if (j >= m)
        return pos - j;
    else
        return -1;
}
int main()
{
	std::ios::sync_with_stdio(false);
    string ss[8] = {"11111111", "10000001", "10111101", "10111101",
                    "10111101", "10111101", "10000001", "11111111"};
    string s[1005];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n - 7; i++)
    {
        int x = -1;
        while ((x = s[i].find(ss[0], x + 1)) != -1)
        {
            int y = i - 8;
            while ((y = BF(s, x, n, ss, 8, y + 8)) != -1)
                ans.insert({y, x});
        }
    }
    for (auto i : ans)
        cout << i.first << " " << i.second << endl;
    return 0;
}