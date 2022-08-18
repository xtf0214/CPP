#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
pii key[30]{
    {2, 1}, {3, 6}, {3, 4}, {2, 3}, {1, 3}, {2, 4}, {2, 5},
     {2, 6}, {1, 8}, {2, 7}, {2, 8}, {2, 9}, {3, 8}, {3, 7},
      {1, 9}, {1, 10}, {1, 1}, {1, 4}, {2, 2}, {1, 5}, 
      {1, 7}, {3, 5}, {1, 2}, {3, 3}, {1, 6}, {3, 2}
};
void solve()
{
    // ios::sync_with_stdio(0);
    string s;
    cin >> s;
    for (auto &i : s)
    {
        if('A'<=i&&i<='Z')
            cout << 3 << " " << 1 << " " << key[i - 'A'].fi << " " << key[i - 'A'].se;
        else
            cout << key[i - 'a'].fi << " " << key[i - 'a'].se;
        cout << endl;
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}