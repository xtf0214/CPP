/** 
 * @file    :   2
 * @author  :   Tanphoon 
 * @date    :   2023/12/11 22:04
 * @version :   2023/12/11 22:04
 * @link    :   https://www.lanqiao.cn/problems/7945/learning/?contest_id=146
 */
#include <bits/stdc++.h>
using namespace std;

int _tm(int x) { return x >= 500 ? x - x / 10 : x; }
int jd(int x) { return x >= 1000 ? x - 150 : x; }
int dy(int x) { return x == 1111 ? 0 : x - x / 20; }
int main() {
    int n;
    cin >> n;
    int sum = 0;
    while (n--) {
        int x;
        cin >> x;
        sum += min({_tm(x), jd(x), dy(x)});
    }
    cout << sum << '\n';
}