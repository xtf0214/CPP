#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
struct LOCTION
{
    int x, y, z;
} A[50005];
bool cmp(const LOCTION &a, const LOCTION &b)
{
    return a.z < b.z;
}
int main()
{
    int n;
    double s = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i].x >> A[i].y >> A[i].z;
    sort(A, A + n, cmp);
    for (int i = 1; i < n; i++)
        s += sqrt(pow(A[i].x - A[i - 1].x, 2) + pow(A[i].y - A[i - 1].y, 2) + pow(A[i].z - A[i - 1].z, 2));
    printf("%.3lf", s);
    return 0;
}