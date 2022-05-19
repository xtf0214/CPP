#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if (b < 0)
        printf("%d/(%d)=%.2lf", a, b, double(a) / b);
    else if (b == 0)
        printf("Error");
    else
        printf("%d/%d=%.2lf", a, b, double(a) / b);
    return 0;
}