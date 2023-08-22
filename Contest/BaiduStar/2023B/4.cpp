#include <bits/stdc++.h>
using namespace std;
int main() {
    long long p, q, n1, n2, n3, mmin = 0x3f3f3f3f, mmax = 0, opt = 0;
    cin >> p >> q >> n1 >> n2 >> n3;
    for (int x = 0; x * n1 <= q; x++)
        for (int y = 0; x * n1 + y * n2 <= q; y++)
            if (long long z = p - x - y; x * n1 + y * n2 + z * n3 == q)
                mmin = min(mmin, z), mmax = max(mmax, z), opt = 1;
    if (opt)
        cout << mmin << " " << mmax;
    else
        cout << -1;
    return 0;
}
