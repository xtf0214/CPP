#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 5;
int k[MAXN], kk[MAXN * MAXN];
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> k[i];
    for (int c = 0; c < n; c++)
        for (int d = 0; d < n; d++)
            kk[c * n + d] = k[c] + k[d];
    sort(k, k + n * n);
    for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++)
            if (binary_search(kk, kk + n * n, k[a] - k[b]))
            {
                cout << "Yes" << endl;
                return 0;
            }
    cout << "No" << endl;
    return 0;
}