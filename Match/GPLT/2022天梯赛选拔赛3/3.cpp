#include <iostream>
using namespace std;
const double PI = 3.14159265;
double cylinder(double r, double h)
{
    return PI * r * r * h;
}
int main()
{
    double r, h;
    cin >> r >> h;
    printf("Volume = %.3lf", cylinder(r, h));
    return 0;
}