#include <bits/stdc++.h>
using namespace std;
struct Stu
{
    int num, t;
    Stu(int num, int t) : num(num), t(t) {}
};
bool cmp(const Stu &a, const Stu &b)
{
    if (a.t != b.t) return a.t > b.t;
    else return a.num < b.num;
}
struct Banwei
{
    vector<Stu> stu;
    void Sort() { sort(stu.begin(), stu.end(), cmp); }
};
int main()
{
    int n, m, k, c, t;
    cin >> n >> m;
    Banwei a[m + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> c >> t;
        a[c].stu.push_back(Stu(i, t));
    }
    for (int i = 1; i <= m; i++)
    {
        a[i].Sort();
        cout << a[i].stu[0].num << " ";
    }
    return 0;
}