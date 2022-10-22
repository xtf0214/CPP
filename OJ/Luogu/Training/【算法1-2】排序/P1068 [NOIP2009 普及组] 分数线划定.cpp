#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct ITVW
{
    int num, score;
} A[5005];
bool cmp(const ITVW &a, const ITVW &b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.num < b.num;
}
int main()
{
    int l, m, n;
    cin >> n >> m;
    l = floor(1.5 * m);
    for (int i = 0; i < n; i++)
        cin >> A[i].num >> A[i].score;
    sort(A, A + n, cmp);
    while (A[l - 1].score == A[l].score)
        l++;
    cout << A[l - 1].score << " " << l << endl;
    for (int i = 0; i < l; i++)
        cout << A[i].num << " " << A[i].score << endl;
    return 0;
}