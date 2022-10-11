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

int vis[15][15];
vector<pii> ans;
void visit(int i, int j, int n, int a)
{
    for (int k = 0; k < n; k++)
        vis[k][j] += a, vis[i][k] += a;
    for (int k = 0; k < n; k++)
    {
        if (0 <= k - j + i && k - j + i < n)
            vis[k - j + i][k] += a;
        if (0 <= j - k + i && j - k + i < n)
            vis[j - k + i][k] += a;
    }
    vis[i][j] -= 3 * a;
}

void dfs(int k, int n)
{
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         printf("%-3d%c", vis[i][j], " \n"[j == n - 1]);
    // cin.get();
    if (k == n)
    {
        for (auto &it : ans)
            cout << it.fi << " " << it.se << endl;
        for (int i = 0; i < n; i++, cout << endl)
            for (int j = 0; j < n; j++)
            {
                if (j == ans[i].se)
                    cout << "##";
                else
                    cout << "[]";
            }
        return;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (vis[i][j] == 0)
            {
                visit(i, j, n, 1);
                ans.push_back({i, j});
                dfs(k + 1, n);
                ans.pop_back();
                visit(i, j, n, -1);
            }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    dfs(0, 4);
    return 0;
}