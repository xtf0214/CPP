#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <fstream>
using namespace std;

using ll = long long;

const int N = 2e5 + 100;

// 求max[l<=i<=r] { min(a_i,i - l + 1) }
// 发现 i - l + 1 在一次询问中是单调递增的
// 那么当我们确定答案mid,那么其实就变成查询[i + mid - 1,r]中max(a_i)
// 因为这时候小于i + mid - 1 的位置受到mid的限制，肯定不会大于mid，那么只有后面
// 通过 max(a_i) 是否大于mid就可以判断正确性了。
// 所以我们使用二分+st表

int n, m;
int a[N];
int f[N][20]; // st表

void init()
{ // 初始化st表
    for (int k = 0; k < 20; k++)
    {
        for (int i = 1; i + (1 << k) - 1 <= n; i++)
        {
            if (!k)
                f[i][k] = a[i];
            else
                f[i][k] = max(f[i][k - 1], f[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int get(int l, int r)
{ // st表获得区间最大值
    if (l > r)
        return 0;
    int len = r - l + 1;
    int k = log(len) / log(2);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

bool check(int mid, int a, int b)
{ // 二分检查函数
    return get(a + mid - 1, b) >= mid;
}

int calc(int a, int b)
{ // 进行二分
    int l = 0, r = b - a + 1;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid, a, b))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}
std::ifstream fin("h.in");
#define cin fin
int main()
{

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    init(); // 初始化st表

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        printf("%d ", calc(a, b));
    }
    return 0;
}