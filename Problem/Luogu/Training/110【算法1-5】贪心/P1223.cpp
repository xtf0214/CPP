// P1223 排队接水
// https://www.luogu.com.cn/problem/P1223
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define time first
#define num second

signed main() {
    int n;
    double sum = 0;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].time;
        a[i].num = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cout << a[i].num << " ";
        sum += i * a[n - 1 - i].time;
    }
    printf("\n%.2lf\n", 1.0 * sum / n);
    return 0;
}