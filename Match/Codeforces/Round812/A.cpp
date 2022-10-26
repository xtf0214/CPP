#include <bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, x, y;
        int mx[2]{0}, my[2]{0};
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            if (x == 0)
                my[y > 0] = max(my[y > 0], abs(y));
            else if (y == 0)
                mx[x > 0] = max(mx[x > 0], abs(x));
        }
        cout << 2 * (mx[0] + mx[1] + my[0] + my[1]) << endl;
    }
    return 0;
}