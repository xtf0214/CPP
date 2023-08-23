#include <bits/stdc++.h>
using namespace std;
#define int long long
#include "debug.h"
signed main() {
    int n;
    cin >> n;
    vector<pair<int, int>> va(n);
    vector<array<int, 3>> vb(n);
    vector<int> st(n, 1);
    // cerr << n << '\n';
    int sum = 0, mx = -1e9, idx1 = n - 1, idx2 = n - 1;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        sum += x;
        mx = max(mx, y);
        va[i] = pair{x, i};
        vb[i] = array<int, 3>{y, x, i};
        cout << i << ' ' << n <<'\n';
    }
    cout << va.size() << '\n';
    
    //  << vb << '\n';
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    sum += mx;
    vector<int> ans;
    ans.push_back(sum);
    for (int i = n - 1; i >= 0; i--) {
        while (st[vb[idx1][2]] == 0)
            idx1--;
        while (st[va[idx2].second == 0])
            idx2--;
        if (i > 0) {

            int tmp1 = vb[idx1][0] + vb[idx1][1] - vb[idx1 - 1][0];
            int tmp2 = va[idx2].first;
            if (tmp1 > tmp2) {
                st[vb[idx1][2]] = 0;
                idx1--;
                sum -= tmp1;
                ans.push_back(sum);
            } else {
                st[va[idx2].second] = 0;
                idx2--;
                sum -= tmp2;
                ans.push_back(sum);
            }
            // cerr << tmp1 << ' ' << tmp2 << '\n';
         }
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
}