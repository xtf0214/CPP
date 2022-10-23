#include <iostream>
#include <algorithm>
using namespace std;
struct STU
{
    int cn, ma, en;
    int num, sum;
} Stu[305];
bool cmp(const STU &a, const STU &b)
{
    if (a.sum != b.sum)
        return a.sum > b.sum;
    else if (a.cn != b.cn)
        return a.cn > b.cn;
    else
        return a.num < b.num;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> Stu[i].cn >> Stu[i].ma >> Stu[i].en;
        Stu[i].sum = Stu[i].cn + Stu[i].ma + Stu[i].en;
        Stu[i].num = i + 1;
    }
    sort(Stu, Stu + n, cmp);
    for (int i = 0; i < 5; i++)
        cout << Stu[i].num << " " << Stu[i].sum << endl;
    return 0;
}
