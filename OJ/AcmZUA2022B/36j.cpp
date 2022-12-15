// 1122 Problem  j	统计满足条件数的个数
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (n; n <= m; n++)
        if (n % 2 == 0 && n % 3 == 0 && n % 7 != 0)
            ans++;
    cout << ans;
    return 0;
}