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

int reverseNumber(vi &a)
{
    int res = 0;
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++)
            if (a[i] > a[j])
                res++;
    return res;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vvi mat(n, vi(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    vi p(n);
    iota(all(p), 0);
    int res = 0, c = 1;
    do
    {

        int mul = 1;
        for (int i = 0; i < n; i++)
            mul *= mat[i][p[i]];
        // print(p);
        // cout << reverseNumber(p) << endl;
        res += (reverseNumber(p) & 1 ? -1 : 1) * mul;

    } while (next_permutation(all(p)));
    cout << res;
    return 0;
}
/* 
4
3 1 -1 2
-5 1 3 -4
2 0 1 -1
1 -5 3 -3 */