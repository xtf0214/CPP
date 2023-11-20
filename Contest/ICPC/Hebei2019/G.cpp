/** 
 * @file    :   G
 * @author  :   Tanphoon 
 * @date    :   2023/11/20 15:23
 * @version :   2023/11/20 15:23
 * @link    :   https://ac.nowcoder.com/acm/contest/903/G
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 1)
        cout << "qiandaoshibai\n";
    else {
        if (n & 1) {
            cout << "qiandaoshibai\n";
        } else {
            cout << "qiandaochenggong\n";
        }
    }
}