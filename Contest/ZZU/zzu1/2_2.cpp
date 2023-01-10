#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    std::ios::sync_with_stdio(false);
    string s1[8] = {"11111111", "10000001", "10111101", "10111101", "10111101", "10111101", "10000001", "11111111"};
    int n, m;
    vector<pair<int, int>> f;
    cin >> n >> m;
    string s[1007];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n - 7; i++)
        for (int j = 0; j < m - 7; j++)
        {
            int flag = 0;
            for (int k = i; k < i + 8; k++)
            {
                for (int l = j; l < j + 8; l++)
                    if (s[k][l] != s1[k - i][l - j])
                    {
                        flag = 1;
                        break;
                    }
                if (flag == 1)
                    break;
            }
            if (flag == 0)
                f.push_back(make_pair(i, j));
        }
    sort(f.begin(), f.end());
    for (int i = 0; i < 3; i++)
        cout << f[i].first << " " << f[i].second << endl;
}
int main()
{
    solve();
    return 0;
}