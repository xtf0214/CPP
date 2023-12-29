/**
 * @file    :   分寝室
 * @author  :   Tanphoon
 * @date    :   2023/12/24 22:07
 * @version :   2023/12/24 22:07
 */
#include <bits/stdc++.h>
using namespace std;

// 分解n的所有因数(不包括1)
vector<int> get(int n) {
    set<int> s;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            s.insert(i), s.insert(n / i);
    s.insert(n);
    return vector<int>(s.begin(), s.end());
}
int main() {
    int n, n1, n0;
    cin >> n0 >> n1 >> n;
    vector<int> a1 = get(n1), a0 = get(n0); // a1:每个男寝可分配的人数，a0:每个女寝可分配的人数
    int mn = 1e9;
    pair<int, int> ans = {0, 0};
    for (int x : a0) {
        for (int y : a1) {
            if (n0 / x + n1 / y == n) { // n0/x女寝宿舍数 n1/y男寝宿舍数
                if (mn > abs(x - y)) {
                    mn = abs(x - y);
                    ans = {n0 / x, n1 / y};
                }
            }
        }
    }
    if (ans == pair<int, int>{0, 0}) {
        cout << "No Solution";
    } else {
        cout << ans.first << ' ' << ans.second;
    }
}