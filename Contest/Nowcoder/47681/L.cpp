/** 
 * @file    :   L
 * @author  :   Tanphoon 
 * @date    :   2023/09/29 12:32
 * @version :   2023/09/29 12:32
 * @link    :   https://ac.nowcoder.com/acm/contest/47681/L
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, k, n;
    cin >> n;
    double ans = 0;
    // 证明只选一个最大的最优
    // 如果优两个最大的相同，(a, b), (a, b) 
    // 那么 (a+a)/(b+b) = a/b
    // 如果有最大和次大，(a, b), (c, d)
    // 即 a/b > c/d
    // 可证明 a/b > (a+c)/(b+d) > c/d
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> k;
        ans = max(ans, 1.0 * a / b);
    }
    printf("%.4lf", ans);
}