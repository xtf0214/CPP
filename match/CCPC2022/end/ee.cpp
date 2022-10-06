#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, st = 0;
    int cnt[128]{0};
    int len[3]{5, 7, 5};
    char c[3];
    char x;
    cin >> n;
    if (n < 17)
        return (cout << "none", 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cnt[x]++;
        if (cnt[x] == len[st])
        {
            memset(cnt, 0, sizeof(cnt));
            c[st] = x;
            st++;
        }
    }
    if (st < 3)
        cout << "none";
    else
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < len[i]; j++)
                cout << c[i];
    return 0;
}