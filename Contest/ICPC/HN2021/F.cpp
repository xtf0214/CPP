#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> G(n + 1, vector<char>(m + 1));
    int y1, x1, y2, x2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> G[i][j];
            if (G[i][j] == '#') {
                y2 = i;
                x2 = j;
            }
            if (i == 1 && G[i][j] == '*') {
                x1 = j;
            }
            if (j == 1 && G[i][j] == '*') {
                y1 = i;
            }
        }
    // cout << x1 << " " << y1 << endl;
    // cout << x2 << " " << y2 << endl;

    cout << x2 - x1 << " " << y1 - y2 << endl;
}