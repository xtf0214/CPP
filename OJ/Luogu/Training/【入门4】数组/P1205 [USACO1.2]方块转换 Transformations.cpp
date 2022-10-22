#include <iostream>
char A[11][11] = {0}, B[11][11] = {0}, C[11][11] = {0}, S[11][11] = {0};
int n;
bool Right90()
{
    /* for (int Y = 0, x = 0; Y <= n - 1, x <= n - 1; Y++, x++)
        for (int X = 0, y = n - 1; X <= n - 1, y >= 0; X++, y--)
            S[Y][X] = A[y][x]; */
    for (int Y = 0; Y <= n - 1; Y++)
        for (int X = 0; X <= n - 1; X++)
            S[Y][X] = A[n - 1 - X][Y];
    for (int Y = 0; Y <= n - 1; Y++)
        for (int X = 0; X <= n - 1; X++)
            if (S[Y][X] != B[Y][X])
                return false;
    return true;
}
bool Right180()
{
    /* for (int Y = 0, y = n - 1; Y <= n - 1, y >= 0; Y++, y--)
        for (int X = 0, x = n - 1; X <= n - 1, x >= 0; X++, x--)
            S[Y][X] = A[y][x]; */
    for (int Y = 0; Y <= n - 1; Y++)
        for (int X = 0; X <= n - 1; X++)
            S[Y][X] = A[n - 1 - Y][n - 1 - X];
    for (int Y = 0; Y <= n - 1; Y++)
        for (int X = 0; X <= n - 1; X++)
            if (S[Y][X] != B[Y][X])
                return false;
    return true;
}
bool Right270()
{
    /* for (int Y = 0, x = n - 1; Y <= n - 1, x >= 0; Y++, x--)
        for (int X = 0, y = 0; X <= n - 1, y <= n - 1; X++, y++)
            S[Y][X] = A[y][x]; */
    for (int Y = 0; Y <= n - 1; Y++)
        for (int X = 0; X <= n - 1; X++)
            S[Y][X] = A[X][n - 1 - Y];
    for (int Y = 0; Y <= n - 1; Y++)
        for (int X = 0; X <= n - 1; X++)
            if (S[Y][X] != B[Y][X])
                return false;
    return true;
}
bool Reflect()
{
    for (int Y = 0; Y <= n - 1; Y++)
        for (int X = 0; X <= n - 1; X++)
            S[Y][X] = A[Y][n - 1 - X];
    for (int Y = 0; Y <= n - 1; Y++)
        for (int X = 0; X <= n - 1; X++)
            if (S[Y][X] != B[Y][X])
                return false;
    return true;
}
bool Combination()
{
    for (int Y = 0; Y <= n - 1; Y++)
        for (int X = 0; X <= n - 1; X++)
            C[Y][X] = A[Y][X]; //先备份A
    for (int Y = 0; Y <= n - 1; Y++)
        for (int X = 0; X <= n - 1; X++)
            S[Y][X] = A[Y][n - 1 - X]; //反射
    for (int Y = 0; Y <= n - 1; Y++)
        for (int X = 0; X <= n - 1; X++)
            A[Y][X] = S[Y][X]; //S替换A
    if (Right90() || Right180() || Right270())
        return true;
    for (int Y = 0; Y <= n - 1; Y++)
        for (int X = 0; X <= n - 1; X++)
            A[Y][X] = C[Y][X]; //还原A
    return false;
}
bool Normal()
{
    for (int Y = 0; Y <= n - 1; Y++)
        for (int X = 0; X <= n - 1; X++)
            if (A[Y][X] != B[Y][X])
                return false;
    return true;
}
using namespace std;
int main()
{
    cin >> n;
    for (int i = 0; i <= n - 1; i++)
        for (int j = 0; j <= n - 1; j++)
            cin >> A[i][j];
    for (int i = 0; i <= n - 1; i++)
        for (int j = 0; j <= n - 1; j++)
            cin >> B[i][j];
    if (Right90())
        cout << 1 << endl;
    else if (Right180())
        cout << 2 << endl;
    else if (Right270())
        cout << 3 << endl;
    else if (Reflect())
        cout << 4 << endl;
    else if (Combination())
        cout << 5 << endl;
    else if (Normal())
        cout << 6 << endl;
    else
        cout << 7 << endl;
    return 0;
}