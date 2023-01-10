// 7-29 找完数
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, None = 1;
    cin >> m >> n;
    for (int x = m; x <= n; x++)
    {
        int sum = 1;
        vector<int> a;
        a.push_back(1);
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
            {
                a.push_back(i), sum += i;
                if (i * i != x)
                    a.push_back(x / i), sum += x / i;
            }
        sort(a.begin(), a.end());
        if (sum == x)
        {
            None = 0;
            printf("%d = ", x);
            for (int i = 0; i < a.size(); i++)
                cout << (string[2]){" + ", ""}[!i] << a[i];
            cout << endl;
        }
    }
    if (None)
        printf("None");
    return 0;
}