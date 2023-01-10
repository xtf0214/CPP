#include <iostream>
using namespace std;
int A[100], Book[100], t[100], n, m, ans;
bool Prime(int x)
{
    if (x == 0 || x == 1)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
void Dfs(int step)
{
    if (step == m)
    {
        int s = 0;
        for (int i = 0; i < m; i++)
            s += A[t[i]];
        if (Prime(s))
            ans++;
        return;
    }
    for (int i = t[step >= 1 ? (step - 1) : 0]; i < n; i++)
        if (Book[i] == 0)
        {
            t[step] = i;
            Book[i] = 1;
            Dfs(step + 1);
            Book[i] = 0;
        }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    Dfs(0);
    cout << ans << endl;
    return 0;
}
