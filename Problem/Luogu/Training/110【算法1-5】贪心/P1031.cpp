// P1031 均分纸牌
// https://www.luogu.com.cn/problem/P1031
#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, sum = 0,ans=0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sum /= n;
    for (int i = 0; i < n - 1; i++)
        if (a[i] - sum) {
            a[i + 1] += a[i] - sum;
            ans++;
        }
    cout << ans;
    return 0;
}