#include <iostream>
using namespace std;
int l, r, k, cnt;
bool Circle(int x)
{
    int B[10] = {0}, l = 0;
    while (x > 0)
    {
        B[l++] = x % 10;
        x /= 10;
    }
    for (int j = 0, k = l - 1; j <= l - 1, k >= 0; j++, k--)
        if (B[j] != B[k])
            return false;
    return true;
}
int main()
{
    cin >> l >> r >> k;
    for (int i = l; i <= r; i++)
        if (i % k == 2)
            if (Circle(i))
                cnt++;
    cout << cnt;
    return 0;
}
/* 
给定L, R, k。求[L,R]范围内回文数且模k（k>=3)余2的数字数量。
输入说明：输入3个整型数字，分别表示L, R和k, 0≤L<R≤1e6。
输出说明：输出在给定区间内满足条件的数的个数。
输入样例：
1 100 3
输出样例：
6
样例解释：
在1到100中间满足条件的数字为：2、5、8、11、44、77 */