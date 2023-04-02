#include <bits/stdc++.h>
using namespace std;

int k, m, n, ans;

bool randtest() {
    int res = 0;
    for (int i = 1; i <= m; i++)
        res += rand() % 6 + 1;
    return res == n;
}
int main() {
    cin >> k;
    while (k--) {
        cin >> m >> n;
        int ans = 0;
        for (int i = 1; i <= 1000000; i++)
            if (randtest())
                ans++;
        printf("%.2lf\n", ans / 1000000.0);
    }
}