/** 
 * @file    :   E
 * @author  :   Tanphoon 
 * @date    :   2023/09/28 17:52
 * @version :   2023/09/28 17:52
 * @link    :   https://ac.nowcoder.com/acm/contest/47681/E
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(1001);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    int cnt = 0;
    for (int i = 1; i <= 1000; i++)
        cnt += a[i] / 2;
    cout << cnt / 2 << '\n';
}