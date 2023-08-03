/** 
 * @file    :   E
 * @author  :   Tanphoon 
 * @date    :   2023/08/01 11:18
 * @version :   2023/08/01 11:18
 * @link    :   https://ac.nowcoder.com/acm/contest/62332/E
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;

int f[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for (int i = 1; i * i < N; i++)
        f[i] = 1;
    int n, cnt = 0;
    cin >> n;
    while (n--) {
        int x; 
        cin >> x;
        cnt += f[x];
    }
    cout << cnt << '\n';
    return 0;
}