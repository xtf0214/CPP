#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using matrix = vector<vi>;
using BigInt = string;
#define ctoi(s) for (int i = 0; i < s.size(); s[i++] -= '0')
#define itoc(s) for (int i = 0; i < s.size(); s[i++] += '0')
const int mod = 114514;
BigInt half(BigInt a)
{
    // ctoi(a) to clac  // itoc(s) to print
    if (a.size() == 1 && (a[0] == 1 || a[0] == 0))
        return {0};
    BigInt s;
    int n = a.size();
    if (a[0] / 2) // a[0] >= 2
        s.push_back(a[0] / 2), a[0] %= 2;
    for (int i = 1; i < n; i++)
    {
        s.push_back((a[i - 1] * 10 + a[i]) / 2);
        a[i] = (a[i - 1] * 10 + a[i]) % 2;
    }
    return s;
}
BigInt reverseBin(BigInt a)
{
    // ctoi(a) to clac  // itoc(r) to print
    BigInt r;
    for (; a != BigInt{0}; a = half(a))
        r.push_back(a.back() & 1);
    if (r.empty())
        r = {0};
    return r;
}
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
matrix pow(matrix &A, BigInt n)
{
    matrix B(A.size(), vi(A[0].size()));
    for (int i = 0; i < B.size(); i++)
        B[i][i] = 1;
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] & 1)
            B = B * A;
        A = A * A;
    }
    return B;
}
int main()
{
    BigInt n;
    matrix A{{1, 1, 1}, {1, 0, 0}, {0, 1, 0}}, res;
    matrix f{{2}, {1}, {1}}, fn; // M[f(2), f(1), f(0)] fn[f(n+2), f(n+1), f(n)]
    cin >> n;
    ctoi(n);
    if (n.size() == 1 && n[0] < 3)
        return cout << f[2 - n[0]][0], 0;
    n = reverseBin(n);
    res = pow(A, n);
    fn = res * f;
    cout << fn[2][0];
    return 0;
}