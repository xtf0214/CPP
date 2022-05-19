#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, q, a, b;
    int y = 0, x = 0;
    bool used[2][100005];
    cin >> n >> m >> q;
    while (q--)
    {
        cin >> a >> b;
        if ((a == 0 && (b < 1 || b > m)) || (a == 1 && (b < 1 || b > n)))
            continue;
        if (!used[a][b])
        {
            a ? y++ : x++;
            used[a][b] = true;
        }
    }
    cout << m * n - y * m - x * n + x * y;
    return 0;
}