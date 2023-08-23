#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 2;

int n, a[N], b[N], c[N], ans[N];
pair<int, int> va[N];
array<int, 3> vb[N];

signed main() {
    cin >> n;
    int sum = 0, my = - 1;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        va[i] = {x, i};
        vb[i] = {y, x, i};
        sum += x; 
        my = max(my, y);
    }
    sum += my;
    int cnt = 0;
    ans[++cnt] = sum;
    sort(va + 1, va + n + 1);
    sort(vb + 1, vb + n + 1);
    int k = n - 1;
    int idx1 = n, idx2 = n;
    while (k--) {
        while (c[va[idx1].second] == 1)
            idx1--;
        while (c[vb[idx2][2]] == 1)
            idx2--;
        if (va[idx1].second == vb[idx2][2])
            --idx1;
        while (c[va[idx1].second] == 1)
            idx1--;
        int temp1 = sum - va[idx1].first;
        int idx3 = idx2 - 1;
        while (c[vb[idx3][2]] == 1)
            --idx3;
        int temp2 = sum - vb[idx2][0] - vb[idx2][1] + vb[idx3][0];
        if (temp1 < temp2) {
            c[va[idx1].second] = 1;
            ans[++cnt] = temp1;
            sum = temp1;
        } else {
            c[vb[idx2][2]] = 1;
            ans[++cnt] = temp2;
            sum = temp2;
        }
    }
    for (int i = n; i; i--)
        cout << ans[i] << endl;
    return 0;
}