#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using matrix = vector<vector<int>>;

#define sign(x) ((x)&1 ? -1 : 1)
#define bitGet(x, i) (x >> i & 1)
#define bitSet1(x, i) (x | 1 << i)

void printMatrix(const matrix &A) {
    for (int i = 0; i < A.size(); i++, cout << endl)
        for (int j = 0; j < A[0].size(); j++)
            cout << A[i][j] << " ";
}
int det(const matrix A, int y = 0, int x = 0) {
    int s = 0;
    int n = A.size();
    int m = n - __builtin_popcount(y); // 余子式阶数
    vector<int> xx, yy;
    for (int i = 0; i < n; i++) {
        if (!bitGet(y, i))
            yy.push_back(i);
        if (!bitGet(x, i))
            xx.push_back(i);
    }
    if (m <= 1)
        return A[yy[0]][xx[0]];
    for (int i = 0; i < m; i++)
        s += sign(i) * A[yy[i]][xx[0]] * det(A, bitSet1(y, yy[i]), bitSet1(x, xx[0]));
    return s;
}
matrix adjoint(const matrix &A) {
    int n = A.size();
    matrix B(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            B[j][i] = sign(i + j) * det(A, bitSet1(0, i), bitSet1(0, j));
    return B;
}
matrix operator*(const matrix &A, const matrix &B) {
    matrix C(A.size(), vector<int>(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
            for (int j = 0; j < B[0].size(); j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
    return C;
}
int main() {
    matrix A;
    // A = {{5, 7, 8}, {2, 3, 4}, {1, 6, 9}};
    A = {{1, 2, 3}, {2, 2, 1}, {3, 4, 3}};
    matrix B = adjoint(A);
    matrix C = A * B;
    printMatrix(B);
    cout << endl;
    printMatrix(C);
    cout << endl;
    cout << det(A) << endl;
    return 0;
}
