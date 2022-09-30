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

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    for (int i = 1; cin >> n && n != 0; i++)
    {
        printf("Game %d:\n", i);
        vi a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        while (true)
        {
            map<int, int> vis;
            int A = 0, B = 0;
            for (int i = 0; i < n; i++)
            {
                cin >> b[i];
                if (a[i] == b[i])
                    A++;
                else
                    vis[a[i]]++;
            }
            if ((*max_element(all(b)) == 0))
                break;
            for (int i = 0; i < n; i++)
                if (a[i] != b[i] && (vis.find(b[i]) != vis.end() && vis[b[i]] != 0))
                    B++, vis[b[i]]--;
            printf("(%d,%d)\n", A, B);
        }
    }
    return 0;
}