#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int rec[N];
vector<int> choice[N];
int n, m;
int now = 1;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        choice[i].resize(k + 1);
        for (int j = 1; j <= k; j++)
            cin >> choice[i][j];
    }
    for (int i = 1; i <= m; i++) {
        int op, j;
        cin >> op >> j;
        if (op == 0) {
            now = choice[now][j];
        } else if (op == 1) {
            rec[j] = now;
            cout << now << endl;
        } else if (op == 2) {
            now = rec[j];
        }
    }
    cout << now;
    return 0;
}
