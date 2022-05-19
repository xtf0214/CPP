#include <iostream>
using namespace std;
int x, A[15], n;
string B[60000];
void Dfs(int step)
{
    if (step == 10)
    {
        int s = 0;
        for (int i = 0; i < 10; i++)
            s += A[i];
        if (s == x)
        {

            for (int i = 0; i < 10; i++)
                B[n] += (A[i] + '0'), B[n] += " ";
            n++;
        }
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        A[step] = i;
        Dfs(step + 1);
    }
}
int main()
{
    cin >> x;
    if (x < 10 || x > 30)
    {
        cout << 0 << endl;
        return 0;
    }
    Dfs(0);
    cout << n << endl;
    for (int i = 0; i < n; i++)
        cout << B[i] << endl;
    return 0;
}