/** 
 * @file    :   A
 * @author  :   Tanphoon 
 * @date    :   2023/09/29 11:28
 * @version :   2023/09/29 11:28
 * @link    :   https://ac.nowcoder.com/acm/contest/47681/A
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int cnt0 = 0, cnt1 = 1;
    while (n--) {
        int x;
        cin >> x;
        if (x == 0) {
            m -= 2;
        } else {
            m--;
        } 
    }
    cout << (m < 0 ? "yes" : "no");
}