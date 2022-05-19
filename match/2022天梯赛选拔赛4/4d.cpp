#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    double t = log(fabs(cos(b) + a * sin(b))) / a / b;
    printf("%.3lf",exp(t));
}