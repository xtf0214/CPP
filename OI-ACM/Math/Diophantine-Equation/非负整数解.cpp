#include <iostream>
using namespace std;
int x[101];
void dfs(int k, int m, int n)
{
    if (k == 1)
    {
        x[k] = n;
        for (int i = 1; i <= m; i++)
            cout << x[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i <= n; i++)
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