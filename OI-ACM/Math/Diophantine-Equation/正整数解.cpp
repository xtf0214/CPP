#include <iostream>
using namespace std;
int x[101];
int cnt[1001]; //
void dfs(int k, int m, int n)
{
    if (k == 1)
    {
        x[k] = n;
        for (int i = 1; i <= m; i++)
            cout << x[i] << " \n"[i == m];
        return;
    }
    for (int i = 1; i <= n - k + 1; i++)
    {
        x[k] = i;
        dfs(k - 1, m, n - i);
    }
}
int main()
{
    dfs(3, 3, 4);
    return 0;
}