#include <bits/stdc++.h>
using namespace std;
int main()
{
    double k1, l, k2;
    int a;
    cin >> k1 >> a >> k2;
    if (a == 0)
        l = k1 * 2.455;
    else if (a == 1)
        l = k1 * 1.26;
    printf("%.2lf ", l);
    if (k2 < l)
        cout << "T_T";
    else
        cout << "^_^";
    return 0;
}