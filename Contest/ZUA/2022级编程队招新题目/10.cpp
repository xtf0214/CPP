#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e5 + 5;
int main() {
    pii arr[N];
    int ans[6]{0};
    int n, m, i;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        arr[i].first = i, arr[i].second = i;
    for (int j = 1; j <= m; j++) {
        cin >> i;
        arr[i].second = n + j;
    }
    sort(arr + 1, arr + n + 1, [](const pii &a, const pii &b) { return a.second < b.second; });
    for (int i = 1; i <= 5; i++)
        ans[i] = arr[i].first;
    sort(ans + 1, ans + 6);
    for (int i = 1; i <= 5; i++)
        cout << ans[i] << " \n"[i == 5];
    return 0;
}
