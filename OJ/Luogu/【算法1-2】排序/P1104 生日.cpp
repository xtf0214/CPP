#include <iostream>
#include <algorithm>
using namespace std;
struct STU
{
    string s;
    int y, m, d, od;
} A[105];
bool cmp(const STU &a, const STU &b)
{
    if (a.y != b.y)
        return a.y < b.y;
    else if (a.m != b.m)
        return a.m < b.m;
    else if (a.d != b.d)
        return a.d < b.d;
    else
        return a.od > b.od;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].s >> A[i].y >> A[i].m >> A[i].d;
        A[i].od = i;
    }
    sort(A, A + n, cmp);
    for (int i = 0; i < n; i++)
        cout << A[i].s << endl;
    return 0;
}