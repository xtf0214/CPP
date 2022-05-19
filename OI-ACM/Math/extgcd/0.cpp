#include <iostream>
using namespace std;
void extgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
        x = 1, y = 0;
    else {
        extgcd(b, a % b, y, x);
        y -= a / b * x; // y = y - a / b * x = x' - a / b * y' = y'' - a / b * y'
    }
}
int main()
{
    int a, b, x, y;
    cin >> a >> b;
    extgcd(a, b, x, y);
    cout << x << " " << y;
    return 0;
}