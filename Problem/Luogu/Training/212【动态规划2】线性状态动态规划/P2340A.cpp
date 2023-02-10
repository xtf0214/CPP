/**
 * @file    :   P2340
 * @author  :   Tanphoon
 * @date    :   2023/02/10 17:02
 * @version :   2023/02/10 17:02
 */
#include <bits/stdc++.h>
using namespace std;

template <typename T, int l, int r> class NegaIdArray {
    vector<T> dat;

  public:
    NegaIdArray(T a = 0) : dat(vector<T>(r - l + 1, a)) {}
    T &operator[](int i) { return dat[i - l]; }
};
const int MR = 400 * 1000;
const int INF = 0x3f3f3f3f;

int n;
vector<int> IQ, EQ;
int solve() {
    vector f(2, NegaIdArray<int, -MR, MR>(-INF));
    f[0][0] = f[1][0] = 0;
    int cr = 1;
    for (int i = 1; i <= n; i++, cr ^= 1)
        for (int j = -MR; j <= MR; j++) {
            if (-MR <= j - IQ[i] && j - IQ[i] <= MR)
                f[cr][j] = max(f[cr ^ 1][j], f[cr ^ 1][j - IQ[i]] + EQ[i]);
            else
                f[cr][j] = f[cr ^ 1][j];
        }
    int ans = -INF;
    for (int i = 0; i <= MR; i++)
        if (f[cr ^ 1][i] >= 0)
            ans = max(ans, f[cr ^ 1][i] + i);
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