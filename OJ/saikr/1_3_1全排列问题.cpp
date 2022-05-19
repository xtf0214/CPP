#include <iostream>
using namespace std;
bool book[10];
int x[10];
void dfs(int k, int n)
{
    if (k == n + 1)
    {
        for (int i = 1; i <= n; i++)
            cout << x[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (book[i] == false)
        {
            x[k] = i;
            book[i] = true;
            dfs(k + 1, n);
            book[i] = false;
        }
}
int main()
{
    int n;
    cin >> n;
    dfs(1, n);
    return 0;
}