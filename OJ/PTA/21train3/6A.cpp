#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using matrix = vector<vi>;
const int mod = 114514;
matrix operator*(matrix &A, matrix &B)
{
    int n = A.size(), l = B.size(), m = B[0].size();
    matrix C(n, vi(m));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < l; k++)
            for (int j = 0; j < m; j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}
matrix pow(matrix &A, ll n)
{
    matrix B(A.size(), vi(A[0].size()));
    for (int i = 0; i < B.size(); i++)
        B[i][i] = 1;
    while (n)
    {
        if (n & 1)
            B = B * A;
        A = A * A;
        n >>= 1;
    }
    return B;
}
int main()
{
    ll n;
    matrix A{{1, 1, 1}, {1, 0, 0}, {0, 1, 0}}, res;
    matrix f{{4}, {2}, {1}}, fn;
    cin >> n;
    if (n < 4)
        return cout << f[3 - n][0], 0;
    res = pow(A, n - 3);
    fn = res * f;
    cout << fn[0][0];
    return 0;
}