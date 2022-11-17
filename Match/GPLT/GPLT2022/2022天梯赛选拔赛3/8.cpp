// 7-8 圆形体体积计算器
#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535;
int main()
{
    while (true)
    {
        int op;
        double r, h;
        printf("1-Ball\n2-Cylinder\n3-Cone\nother-Exit\n"
               "Please enter your command:\n");
        cin >> op;
        if (op == 1)
        {
            printf("Please enter the radius:\n");
            cin >> r;
            printf("%.2lf\n", 4 * PI * pow(r, 3) / 3);
        }
        else if (op == 2)
        {
            printf("Please enter the radius and the height:\n");
            cin >> r >> h;
            printf("%.2lf\n", PI * r * r * h);
        }
        else if (op == 3)
        {
            printf("Please enter the radius and the height:\n");
            cin >> r >> h;
            printf("%.2lf\n", PI * r * r * h / 3);
        }
        else
            break;
    }
    return 0;
}