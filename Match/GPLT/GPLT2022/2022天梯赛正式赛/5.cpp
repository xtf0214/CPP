#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> ans;
    int a[10];
    int n;
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    cin >> n;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 6; j >= 1; j--)
        {
            if (j == a[i])
                continue;
            else
                ans.push_back(j);
        }
        i ? printf(" %d", ans[n - 1]) : printf("%d", ans[n - 1]);
        ans.clear();
    }
    return 0;
}