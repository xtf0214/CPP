#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
const int MAX = 10005;
typedef vector<vector<int>> matrix;
typedef long long ll;
matrix operator*(matrix &A, matrix &B)
{
    matrix C(A.size(), vector<int>(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
            for (int j = 0; j < B[0].size(); j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
    return C;
}
matrix pow(matrix &A, ll n)
{
    matrix B(A.size(), vector<int>(A[0].size()));
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
    ll n = 2;
    matrix A(2, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    A = A * A;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    return 0;
}