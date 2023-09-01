#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Matrix = vector<vector<int>>;
Matrix operator*(const Matrix &A, const Matrix &B) {
    Matrix C(A.size(), vector<int>(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
            for (int j = 0; j < B[0].size(); j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
    return C;
}
Matrix pow(Matrix &A, ll n) {
    Matrix B(A.size(), vector<int>(A[0].size()));
    for (int i = 0; i < B.size(); i++)
        B[i][i] = 1;
    for (; n; n >>= 1, A = A * A)
        if (n & 1)
            B = B * A;
    return B;
}
int main() {
    ll n = 2;
    Matrix A(2, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    A = A * A;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " \n"[j == n - 1];
    return 0;
}