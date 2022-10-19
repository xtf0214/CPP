// 1044 Problem  b	绝对值排序（第六讲）
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i == v.size() - 1], ++i)

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        vi a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(all(a), [](int a, int b)
             { return abs(a) > abs(b); });
        print(a);
    }
    return 0;
}