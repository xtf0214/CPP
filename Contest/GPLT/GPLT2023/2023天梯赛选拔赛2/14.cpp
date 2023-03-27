#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int f[N], a[N];
int main() {
    int n, W;
    cin >> n >> W;
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int w = 1; w <= W; w++)
        for (int i = 0; i < n; i++)
            if (w - a[i] >= 0)
                if (f[w] > f[w - a[i]] + 1)
                    f[w] = f[w - a[i]] + 1;
    cout << f[W];
    return 0;
}