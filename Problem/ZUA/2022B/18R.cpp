// 1034 Problem  R	百元百鸡(第四讲）
#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n, flag = 0;
    cin >> m >> n;
    for (int i = 0; i <= n / 5; i++)
        for (int j = 0; j <= n / 3; j++)
            for (int k = 0; k <= m - i - j; k++)
                if (3 * (i * 5 + j * 3) + k == 3 * n && i + j + k == m) {
                    cout << i << " " << j << " " << k << endl;
                    flag = 1;
                }
    if (flag == 0)
        cout << "no answer";
    return 0;
}