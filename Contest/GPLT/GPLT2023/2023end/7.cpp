/** 
 * @file    :   L1-7 分寝室
 * @author  :   Tanphoon 
 * @date    :   2023/04/24 12:13
 * @version :   2023/04/24 12:13
 * @link    :   
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> breakdown(int x) {
    vector<int> res;
    for (int i = 1; i * i <= x; i++)
        if (x % i == 0) {
            res.push_back(i);
            if (i * i != x)
                res.push_back(x / i);
        }
    return res;
}
int main() {
    int n0, n1, n;
    cin >> n0 >> n1 >> n;
    vector<int> N0 = breakdown(n0);
    vector<int> N1 = breakdown(n1);
    int mx = INT_MAX, a0, a1;
    for (int i : N0)
        for (int j : N1)
            if (i + j == n) {
                if (mx > abs(n0 / i - n1 / j)) {
                    mx = abs(n0 / i - n1 / j);
                    a0 = i, a1 = j;
                }
            }
    if (mx == INT_MAX)
        puts("No Solution");
    else
        cout << a0 << " " << a1;
}