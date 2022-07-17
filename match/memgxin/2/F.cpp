#include <bits/stdc++.h>
#include "D:\Code\CPP\Debug\timer.h"
using namespace std;
using pii = pair<int, int>;
const int MAX = 1e9 + 5;
bool pow3[MAX];
vector<pii> p;
int res = 0;
int fastPow(int x, int n)
{
    int s = 1;
    for (; n; n >>= 1, x = x * x)
        if (n & 1)
            s *= x;
    return s;
}
void dfs(int k = 0, int s = 1)
{
    if (k == p.size())
    {
        // cout << s << endl;
        if (pow3[s])
        {
            res++;
        }
        return;
    }
    for (int i = 0; i < p[k].second; i++)
        dfs(k + 1, s * fastPow(p[k].first, i));
}
int main()
{
    int T, n, x;
    double t1 = getTime();
    for (int i = 1, mul = 1, sq; mul <= 1e9; mul = i * i * i, sq = sqrt(mul), i++)
        if (sqrt(mul) == sq)
            pow3[sq] = true;
    for (int i = 0; i < MAX; i++)
        if (pow3[i])
            cout << i << endl;
    double t2 = getTime();
    cout << t2 - t2 << endl;
    cin >> T;
    while (T--)
    {
        cin >> n;
        x = n;
        p.clear();
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
            {
                int cnt = 0;
                while (x % i == 0)
                    x /= i, cnt++;
                p.push_back({i, cnt});
            }
        if (x != 1)
            p.push_back({x, 1});
        dfs();
    }
    return 0;
}