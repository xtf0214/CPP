#include <iostream>
#include <cstdio>
#include <iostream>
using namespace std;
int A[510][510] = {0},B[510][510] = {0};
void Left90(int x, int y, int r)
{
    for (int i = y - r; i <= y + r; i++)
        for (int j = x - r; j <= x + r; j++)
            B[i][j] = A[j][2 * y - i];
    for (int i = y - r; i <= y + r; i++)
        for (int j = x - r; j <= x + r; j++)
            A[i][j] = B[i][j];
}
void Right90(int x, int y, int r)
{    
    for (int i = y - r; i <= y + r; i++)
        for (int j = x - r; j <= x + r; j++)
            B[i][j] = A[2 * x - j][i];
    for (int i = y - r; i <= y + r; i++)
        for (int j = x - r; j <= x + r; j++)
            A[i][j] = B[i][j];
}
int main()
{
    int n, m, x, y, r, z;
    cin >> n >> m;
    for (int i = 1, t = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            A[i][j] = t++;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> r >> z;
        if (z == 0)
            Right90(x, y, r);
        else if (z == 1)
            Left90(x, y, r);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    return 0;
}