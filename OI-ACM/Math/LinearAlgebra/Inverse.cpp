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
matrix inverse(const matrix &A) {
    int n = A.size();
    matrix B(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            B[i][j] = sign(i + j) * det(A, bitSet1(0, i), bitSet1(0, j));
    return B;
}

int main() {
    matrix A;
    A = {{5, 7, 8}, {2, 3, 4}, {1, 6, 9}};
    matrix B = inverse(A);
    printMatrix(B);
    cout << det(A) << endl;
    return 0;
}
