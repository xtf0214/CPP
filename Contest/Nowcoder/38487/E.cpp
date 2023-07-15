/**
 * @file    :   E 睡大觉
 * @author  :   Tanphoon
 * @date    :   2023/06/16 20:52
 * @version :   2023/06/16 20:52
 * @link    :   https://ac.nowcoder.com/acm/contest/38487/E
 */
#include <bits/stdc++.h>
using namespace std;
int month[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int y, m, d;
bool run() { return y % 400 == 0 || y % 100 != 0 && y % 4 == 0; }
void nxtday() {
    if (++d > month[m] + (m == 2 && run()))
        d = 1, ++m;
    if (m > 12)
        m = 1, ++y;
}
void solve() {
    int n, cnt = 0;
    scanf("%d-%d-%d", &y, &m, &d);
    scanf("%d", &n);
    int t1 = 0, t2 = 0;
    for (int i = 0; i < n; i++) {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        t2 = 3600 * hh + 60 * mm + ss;
        if (t2 <= t1)
            nxtday();
        if ((m + d) % 2 == 0)
            cnt++;
        t1 = t2;
    }
    cout << cnt << '\n';
}
int main() {
    solve();
    return 0;
}