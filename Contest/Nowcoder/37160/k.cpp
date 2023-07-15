// 糟糕的一天
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;
int a[MAX] = {0};
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int j = 1; j < n; j++)
        for (int i = j + 1; i <= n; i++)
            if (a[j] < a[i])
            {
                cnt++;
                break;
            }
    cout << cnt << endl;
    return 0;
}