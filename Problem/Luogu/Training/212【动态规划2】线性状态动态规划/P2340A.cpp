/**
 * @file    :   P2340
 * @author  :   Tanphoon
 * @date    :   2023/02/10 17:02
 * @version :   2023/02/10 17:02
 */
#include <bits/stdc++.h>
using namespace std;

#define at(i) i + MR
const int MR = 400 * 1000;
const int INF = 0x3f3f3f3f;

int n;
vector<int> IQ, EQ;
int solve() {
    vector f(2, vector<int>(2 * MR + 5, -INF));
    f[0][at(0)] = f[1][at(0)] = 0;
    int cr = 1;
    for (int i = 1; i <= n; i++, cr ^= 1)
        for (int j = -MR; j <= MR; j++) {
            if (-MR <= j - IQ[i] && j - IQ[i] <= MR)
                f[cr][at(j)] = max(f[cr ^ 1][at(j)], f[cr ^ 1][at(j) - IQ[i]] + EQ[i]);
            else
                f[cr][at(j)] = f[cr ^ 1][at(j)];
        }
    int ans = -INF;
    for (int i = 0; i <= MR; i++)
        if (f[cr ^ 1][at(i)] >= 0)
            ans = max(ans, f[cr ^ 1][at(i)] + i);
    return ans;
}
int main() {
    cin >> n;
    IQ.resize(n + 1), EQ.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> IQ[i] >> EQ[i];
    cout << solve();
    return 0;
}