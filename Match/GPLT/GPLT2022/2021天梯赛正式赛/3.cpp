#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    double p;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        if (p < m)
            printf("On Sale! %.1lf\n", p);
    }
    return 0;
}