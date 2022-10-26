#include <bits/stdc++.h>
using namespace std;
double y;
double f(double x) { return 0.5 * sqrt(x * x * x) + sin(x) - y; }
double df(double x) { return 0.75 * sqrt(x) + cos(x); }
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> y;
        int k = 0;
        double x1 = 1e12, x0;
        do
        {
            x0 = x1;
            x1 = x0 - f(x0) / df(x0);
        } while (abs(x0 - x1) > 1e-6);
        printf("%.6lf\n", x1);
    }
}