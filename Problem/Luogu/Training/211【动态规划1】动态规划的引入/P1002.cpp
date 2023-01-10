// P1002 过河卒
// https://www.luogu.com.cn/problem/P1002
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int vec[8][2]{{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
const int N = 40;

ll dp[N][N];
bool s[N][N];
int ex, ey, mx, my;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> ey >> ex >> my >> mx;
    ey += 2, ex += 2, my += 2, mx += 2;
    dp[2][1] = 1;
    s[my][mx] = 1;
    for (auto [ty, tx] : vec)
        s[my + ty][mx + tx] = 1;
    for (int i = 2; i <= ey; i++)
        for (int j = 2; j <= ex; j++) {
            if (s[i][j])
                continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    cout << dp[ey][ex];
    return 0;
}
