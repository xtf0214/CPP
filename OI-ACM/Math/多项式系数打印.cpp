#include <iostream>
using namespace std;
int n;
void NumberOut(double a, int i)
{
    if (a == 0)
        return;
    if (i != n && a > 0)
        cout << "+";
    if (a != 1 || a != -1)
        cout << a;
    if (a == -1)
        cout << "-";
    if (i > 1)
        cout << "x^" << i;
    if (i == 1)
        cout << "x";
}