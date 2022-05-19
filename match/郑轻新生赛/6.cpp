#include <bits/stdc++.h>
using namespace std;
struct Stu
{
    string name;
    int id, times;
};
bool cmp(const Stu &a, const Stu &b)
{
    if (a.times != b.times)
        return a.times < b.times;
    else
        return a.id < b.id;
}
int main()
{
    int n, h, m, s;
    cin >> n;
    Stu a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].name;
        scanf("%d:%d:%d", &h, &m, &s);
        a[i].times = h * 3600 + m * 60 + s;
        a[i].id = i;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
        cout << a[i].name << "\n";
    return 0;
}