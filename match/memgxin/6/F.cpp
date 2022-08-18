#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(0);
    int n, s = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], s ^= a[i];
    if (s == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    sort(a.begin(), a.end(), greater<int>());
    for (int k = 1; k < a[0]; k++)
        for (int i = 0; a[i] - k > 0; i++)
            for (int j = i + 1; j < n; j++)
            {
                printf("k = %d: %d %d\n", k, a[i], a[j]);
                int u = s ^ a[i] ^ a[j];
                int x = a[i] - k, y = a[j] + k;
                if ((u ^ x ^ y) == 0)
                {
                    cout << k << endl;
                    return 0;
                }
            }
    cout << -1 << endl;
    return 0;
}