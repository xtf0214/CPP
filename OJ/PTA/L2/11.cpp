// 7-11 列车调度
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(v) v.begin(), v.end()

void solve()
{
    vi rail;
    int n, m, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (rail.size() == 0 || rail.back() < x)
            rail.push_back(x);
        else
            *upper_bound(all(rail), x) = x; // 查找第一个大于x的元素并返回地址
    }
    cout << rail.size();
}
int main()
{
    solve();
    return 0;
}