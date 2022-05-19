#include <iostream>
#include <cstdio>
using namespace std;
int A[1001], Book[1001], t[1001], n, m;
void Permutation(int step)
{
    if (step == m)
    {
        for (int i = 0; i < m; i++)
            printf("%3d", A[t[i]]);
        cout << endl;
        return;
    }
    for (int i = t[(step - 1) >= 0 ? (step - 1) : 0]; i < n; i++)
        if (Book[i] == 0)
        {
            t[step] = i;
            Book[i] = 1;
            Permutation(step + 1);
            Book[i] = 0;
        }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        A[i] = i + 1;
    Permutation(0);
    return 0;
}
