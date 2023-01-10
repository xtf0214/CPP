#include <iostream>
using namespace std;
bool Prime(int x)
{
    if (x == 2)
        return true;
    else if (x < 2 || x % 2 == 0)
        return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}
bool CheckCircle(int x)
{
    int B[10] = {0}, l = 0;
    while (x > 0)
    {
        B[l++] = x % 10;
        x /= 10;
    }
    for (int j = 0, k = l - 1; j <= l - 1, k >= 0; j++, k--)
        if (B[j] != B[k])
            return false;
    return true;
}
int main()
{
    int a, b, n = 0;
    int A[20000] = {0};
    cin >> a >> b;
    for (int i = a; i <= b; i++)
        if (CheckCircle(i))
            A[n++] = i;
    for (int i = 0; i < n; i++)
        if (Prime(A[i]))
            cout << A[i] << endl;
    return 0;
}