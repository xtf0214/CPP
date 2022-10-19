#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i == v.size() - 1], ++i)
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int n, l;
int s[N];
void dfs(int k,int n)
{
    if(k==n)
    {

        return;
    }
    for (int i = 0; i < l;i++)
    {
        s[k] = i;
        bool right = true;
        for (int j = 1; j * 2 <= k + 1;j++)
        {
            bool equal = true;
            for (int jj = 0;jj<)
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}