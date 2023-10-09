/**
 * @file    :   Matrix
 * @author  :   Tanphoon
 * @date    :   2023/09/25 15:09
 * @version :   2023/09/25 15:09
 */
#include <bits/stdc++.h>
using namespace std;

void traceBack(int i, int j, vector<vector<int>> &s) {
    if (i == j) {
        cout << "A" << i;
        return;
    }
    cout << "(";
    traceBack(i, s[i][j], s);
    cout << "*";
    traceBack(s[i][j] + 1, j, s);
    cout << ")";
}
int main() {
    int n = 4;
    vector<int> p = {45, 8, 40, 25, 10};

    vector m(n + 1, vector<int>(n + 1, 1e6));
    vector s(n + 1, vector<int>(n + 1));
    // L = 1
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;
    for (int L = 2; L <= n; L++)
        for (int i = 1, j = i + L - 1; j <= n; i++, j++)
            for (int k = i; k < j; k++) {
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (m[i][j] > t) {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
    cout << m[1][n] << '\n';
    cout << "s:\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cout << s[i][j] << " \n"[j == n];
    cout << "m:\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cout << setw(8) << (m[i][j] == 1e6 ? "INF" : to_string(m[i][j])) << " \n"[j == n];
    traceBack(1, n, s);
    return 0;
}