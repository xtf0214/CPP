#include <bits/stdc++.h>
using namespace std;
int m, n, q, a, b;
int y = 0, x = 0;
bool used[2][100010];
int main() {
    cin >> n >> m >> q;
    while (q--) {
        cin >> a >> b;
        if (!used[a][b]) {
            used[a][b] = true;
            a ? x++ : y++;
        }
    }
    cout << (m - x) * (n - y);
    return 0;
}