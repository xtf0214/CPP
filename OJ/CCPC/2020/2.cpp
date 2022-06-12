#include <bits/stdc++.h>
using namespace std;
int x[10];
int sum = 0, cnt = 0;
void dfs(int k, int m, int n, int st)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << x[i] << " \n"[i == m - 1];
        return;
    }
    for (int i = st; i < n; i++)
    {
        x[k] = i;
        dfs(k + 1, m, n, i);
    }
}
void dfs1(int k, int m, int n, int s)
{
    if (k == m)
    {
        x[k] = n;
        s += n * n;
        cout << s << " - ";
        sum += s;
        cnt++;
        for (int i = 1; i <= m; i++)
            cout << x[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i <= n; i++)
    {
        x[k] = i;
        dfs1(k + 1, m, n - i, s + i * i);
    }
}
int main()
{
    // dfs(0, 3, 3, 0);
    dfs1(1, 4, 5, 0);
    cout << sum / cnt;
}