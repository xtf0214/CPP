#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const double Pi = 3.141592653589793;
void solve_equation(double a, double b, double c, double *x1, double *x2)
{
    double delta = b * b - 4 * a * c;
    if (delta == 0)
        *x1 = *x2 = -b / (2 * a);
    else
    {
        *x1 = (-b + sqrt(delta)) / (2 * a);
        *x2 = (-b - sqrt(delta)) / (2 * a);
    }
} //解方程
bool Number_Out(double x, bool begin)
{
    if (x > 0 && x != 1)
    {
        if (begin)
            cout << x;
        else
            cout << " + " << x;
        return true;
    }
    else if (x == 1)
        return true;
    else if (x == 0)
        return false;
    else if (x < 0)
    {
        cout << " - " << -x;
        return true;
    }
    return true;
} //输出系数
void calc(double a2, double b2, double x0, double y0)
{
    double A, B, C, D, E, F;
    A = a2 + b2;
    B = 2 * a2 * x0;
    C = -2 * b2 * y0;
    D = a2 * (-b2 + x0 * x0 + y0 * y0);
    E = 0;
    F = b2 * (-a2 + x0 * x0 + y0 * y0);
    double x1, x2, m1, m2;
    solve_equation(A, C, F, &m1, &m2);
    x1 = (abs(m1 - y0) > abs(m2 - y0)) ? m1 : m2;
    solve_equation(A, B + C, D + E + F, &m1, &m2);
    x2 = (abs(x0 + m1 - y0) > abs(x0 + m2 - y0)) ? m1 : m2;
    printf("{%f,%f},", x1 - x2, x1);
    /* printf("直线AB恒过定点Q(%f,%f)\n", x1 - x2, x1);
    cout << (Number_Out(A, true) ? "m^2" : "") << " + (" << (Number_Out(B, true) ? "k" : "");
    cout << (Number_Out(C, false) ? "" : "") << ")m" << (Number_Out(D, false) ? "k^2" : "");
    cout << (Number_Out(E, false) ? "k" : "") << (Number_Out(F, false) ? "" : "") << " = 0" << endl;
    cout << "delta = " << (Number_Out(B * B - 4 * A * D, true) ? "k^2" : "");
    cout << (Number_Out(2 * B * C - 4 * A * E, false) ? "k" : "") << (Number_Out(C * C - 4 * A * F, false) ? "" : ""); */ 
}
int main()
{
    system("chcp 65001");
    double a2, b2, x0, y0;
    // cin >> a2 >> b2 >> x0 >> y0;
    // calc(a2, b2, x0, y0);
    for (int i = 0; i <= 360; i++)
    {
        double theta = Pi * i / 180;
        calc(4, 1, 2 * cos(theta), sin(theta));
    }
    getchar();
    getchar();
    return 0;
}
