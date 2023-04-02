#include <bits/stdc++.h>
using namespace std;

int k, m, n, ans;

void dfs(int m, int s) {
    if (s > n)
        return;
    if (m == 0) {
        if (s == n)
            ans++;
        return;
    }
    for (int i = 1; i <= 6; i++)
        dfs(m - 1, s + i);
}
int main() {
    cin >> k;
    while (k--) {
        cin >> m >> n;
        ans = 0;
        dfs(m, 0);
        printf("%.2lf", ans / pow(6, m));
    }
}