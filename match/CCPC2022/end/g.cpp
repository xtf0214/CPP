#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(v) v.begin(), v.end()

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m,q, ans = 0,l,r,i,j,p;
    char c;
    cin >> n >> m;
    vi b(m, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            if (c == '0' && b[j] != 0)
                b[j] = 0;
        }
    cin >> q;
    while(q--)
        cin >> i >> j >> l >> r >> p;
    cout << count(all(b), 1);
    return 0;
}