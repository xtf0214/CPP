#include <iostream>
using namespace std;
int x[10];
void dfs(int k, int st, int n)
{
    if (n == 0)
    {
        if (k == 1)
            return;
        for (int i = 0; i < k; i++)
            i ? (cout << "+" << x[i]) : (cout << x[i]);
        cout << endl;
        return;
    }
    for (int i = st; i <= n; i++)
    {
        x[k] = i;
        dfs(k + 1, i, n - i);
    }
}
int main()
{
    int n;
    cin >> n;
    dfs(0, 1, n);
    return 0;
}