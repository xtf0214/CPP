#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 5;
int N;
// N:可转移状态的个数  f[N]:可转移状态的集合
// SG[]:SG(x)  S[]={SG(y)|x to y}
int f[MAXN], SG[MAXN], S[MAXN];
void getSG(int n)
{
    int i, j;
    memset(SG, 0, sizeof(SG));
    for (int i = 1; i <= n; i++)
    {
        memset(S, 0, sizeof(S));
        for (int j = 0; f[j] <= i && j <= N; j++)
            S[SG[i - f[j]]] = 1;
        for (int j = 0;; j++)
            if (!S[j])
            {
                SG[i] = j;
                break;
            }
    }
}
int main()
{
    cout << (1 != 2 ? "1" : "2");
    return 0;
}