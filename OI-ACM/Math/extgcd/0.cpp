#include <iostream>
using namespace std;
int extgcd(int a, int b, int &x, int &y)
{
    int d;
    if (b == 0)
        x = 1, y = 0, d = a;
    else
    {
        d = extgcd(b, a % b, y, x); // x'  y'
        y -= a / b * x;             // y = y - a / b * x = x' - a / b * y' = y'' - a / b * y'
    }
    printf("%dx+%dy==%d\nx==%d    y==%d\n\n", a, b, d, x, y);
    return d;
}
pair<int, int> exgcd(int a, int b)
{
    if (b == 0)
        return {1, 0};
    else
    {
        auto [x, y] = exgcd(b, a % b);
        return {y, x - a / b * y};
    }
}
int main()
{
    int a, b, x, y;
    cin >> a >> b;
    extgcd(a, b, x, y);
    cout << x << " " << y << endl;
    auto [p, q] = exgcd(a, b);
    cout << p << " " << q;
    return 0;
}