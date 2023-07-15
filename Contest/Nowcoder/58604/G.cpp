/** 
 * @file    :   G 小红过61
 * @author  :   Tanphoon 
 * @date    :   2023/06/01 21:01
 * @version :   2023/06/01 21:01
 * @link    :   https://ac.nowcoder.com/acm/contest/58604/G
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5, mod = 1e9 + 7;

ll f[N], pr6[N], pr[N];
int main() {
    string s;
    s = "2621";
    cin >> s;
    int n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        // s[i]：以第i个字符为结尾的合法子序列个数
        if (s[i] == '1') {
            f[i] = pr6[i - 1] + 1;
        } else {
            f[i] = pr[i - 1] + 1;
        }
        // pr[i]：使用前i个字符的合法子序列个数
        pr[i] = pr[i - 1] + f[i];
        // pr6[i]：前i个中不以6结尾的子序列个数
        if (s[i] != '6')
            pr6[i] = pr6[i - 1] + f[i];
        else
            pr6[i] = pr6[i - 1];
        pr[i] %= mod;
        pr6[i] %= mod;
        f[i] %= mod;
    }
    cout << pr[n] << endl;
}