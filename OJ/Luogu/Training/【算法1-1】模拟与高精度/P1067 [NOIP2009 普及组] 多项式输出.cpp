#include <iostream>
using namespace std;
int n;
int A[101] = {0};
void NumberOut(int a, int k)
{
    if (k == n)
    {
        if (a == 1)
            cout << "x^" << k;
        else if (a == 0)
            cout << "";
        else if (a == -1)
            cout << "-x^" << k;
        else if (a < 0)
            cout << "-" << -a << "x^" << k;
        else
            cout << "" << a << "x^" << k;
    }
    else if (k == 1)
    {
        if (a == 1)
            cout << "+x";
        else if (a == 0)
            cout << "";
        else if (a == -1)
            cout << "-x";
        else if (a < 0)
            cout << "-" << -a << "x";
        else
            cout << "+" << a << "x";
    }
    else if (k == 0)
    {
        if (a == 0)
            cout << "";
        else if (a < 0)
            cout << "-" << -a;
        else
            cout << "+" << a;
    }
    else
    {
        if (a == 1)
            cout << "+x^" << k;
        else if (a == 0)
            cout << "";
        else if (a == -1)
            cout << "-x^" << k;
        else if (a < 0)
            cout << "-" << -a << "x^" << k;
        else
            cout << "+" << a << "x^" << k;
    }
}
int main()
{
    cin >> n;
    for (int i = n; i >= 0; i--)
        cin >> A[i];
    for (int i = n; i >= 0; i--)
        NumberOut(A[i], i);
}