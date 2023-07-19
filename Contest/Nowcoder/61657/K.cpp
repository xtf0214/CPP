/** 
 * @file    :   K
 * @author  :   Tanphoon 
 * @date    :   2023/07/19 17:40
 * @version :   2023/07/19 17:40
 * @link    :   https://ac.nowcoder.com/acm/contest/61657/K
 */
#include <bits/stdc++.h>
using namespace std;

int findPrime(int x, int p) {
    int cnt = 0;
    while (x && x % p == 0)
        cnt++, x /= p;
    return cnt;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> b2(n * 2 + 1), b5(n * 2 + 1);
    vector<int> f2(n * 2 + 1), f5(n * 2 + 1);
    vector<int> h2(n + 1), h5(n + 1);
    vector<int> s2(n + 1), s5(n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        b2[i] = findPrime(i, 2);
        b5[i] = findPrime(i, 5);
        f2[i] = f2[i - 1] + b2[i];
        f5[i] = f5[i - 1] + b5[i];
    }
    for (int i = 1; i <= n; i++) {
        h2[i] = f2[i * 2] - f2[i + 1] - f2[i];
        h5[i] = f5[i * 2] - f5[i + 1] - f5[i];
        s2[i] = s2[i - 1] + h2[i];
        s5[i] = s5[i - 1] + h5[i];
    }
    cout << min(s2[n], s5[n]) << '\n';
    return 0;
}