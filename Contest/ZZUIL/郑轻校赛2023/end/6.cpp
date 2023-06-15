/** 
 * @file    :   3036: 莫比乌斯最大值isUsefulAlgorithm
 * @author  :   Tanphoon 
 * @date    :   2023/06/15 15:01
 * @version :   2023/06/15 15:01
 * @link    :   http://acm.zzuli.edu.cn/problem.php?id=3036
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
int read(int x = 0) { return cin >> x, x; }

int n, a[N], b[N];
ll ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        a[read()] = 1;
    for (int j = 1; j <= n; j++)
        b[read()] = 1;
    for (int i = 1; i <= 100000; i++) {
        ll maxa = 0, maxb = 0;
        for (int j = i; j <= 100000; j += i) {
            if (a[j])
                maxa = j;
            if (b[j])
                maxb = j;
        }
        ans = max(ans, maxa * maxb * i);
    }
    cout << ans;
    return 0;
}