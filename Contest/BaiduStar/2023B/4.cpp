/** 
 * @file    :   4
 * @author  :   Tanphoon 
 * @date    :   2023/08/22 16:07
 * @version :   2023/08/22 16:07
 * @link    :   https://www.matiji.net/exam/brushquestion/12/4347/179CE77A7B772D15A8C00DD8198AAC74?from=1
 */
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
