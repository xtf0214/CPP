#include <bits/stdc++.h>
using namespace std;
double y;
double f(double x) { return 0.5 * sqrt(x * x * x) + sin(x); }
double df(double x) { return 0.75 * sqrt(x * x * x) + cos(x); }
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> y;
        double l=0, r=10e12, mid;
        
        while (r - l > 1e-6)
        {
            mid = (l + r) / 2;
            if (f(mid) - y > 0)
                r = mid;
            else
                l = mid;
        }
        printf("%.6lf\n", mid);
    }
}