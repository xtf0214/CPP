#include <iostream>
#include <cmath>
using namespace std;
int A[1029][1029];
void fill(int y, int x, int l)
{
    if (l == 2)
    {
        A[y][x] = 0;
        return;
    }
    for (int i = y; i <= y + l / 2 - 1; i++)
        for (int j = x; j <= x + l / 2 - 1; j++)
            A[i][j] = 0;
    fill(y, x + l / 2, l / 2);
    fill(y + l / 2, x, l / 2);
    fill(y + l / 2, x + l / 2, l / 2);
}
int main()
{
    int n, l;
    cin >> n;
    l = pow(2, n);
    for (int y = 1; y <= l; y++)
        for (int x = 1; x <= l; x++)
            A[y][x] = 1;
    fill(1, 1, l);
    for (int y = 1; y <= l; y++)
        for (int x = 1; x <= l; x++)
            cout << A[y][x] << " \n"[x == l];
}