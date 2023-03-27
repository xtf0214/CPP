#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<bool> row(n + 1), col(m + 1);
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 0 && !row[x]) {
            n--;
            row[x] = true;
        } else if (op == 1 && !col[x]) {
            m--;
            col[x] = true;
        }
    }
    cout << n * m;
    return 0;
}