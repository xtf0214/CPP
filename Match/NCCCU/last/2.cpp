#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a, b, c, d, ans = 1;
    double Sum[20] = {0};
    cin >> a >> b >> c >> d;
    Sum[0] = a + b + c + d;
    Sum[1] = a + b - c + d;
    Sum[2] = a + b * c + d;
    Sum[3] = a + b / c + d;

    Sum[4] = a - b + c + d;
    Sum[5] = a - b - c + d;
    Sum[6] = a - b * c + d;
    Sum[7] = a - b / c + d;

    Sum[8] = a * b + c + d;
    Sum[9] = a * b - c + d;
    Sum[10] = a * b * c + d;
    Sum[11] = a * b / c + d;

    Sum[12] = a / b + c + d;
    Sum[13] = a / b - c + d;
    Sum[14] = a / b * c + d;
    Sum[15] = a / b / c + d;

    sort(Sum, Sum + 16);
    for (int i = 1; i < 16; i++)
        if (Sum[i] != Sum[i - 1])
            ans++;
    cout << ans;
    return 0;
}
/* 
给定4个正整数a,b,c,d。求算数表达式a？b？c+d的数学结果（四舍五入取整），其中?可以为加减乘除中的一个，需考虑优先级，不存在括号。问能得到多少个不同的整数。
输入说明：a,b,c,d 四个不超过1e5的正整数，
输出说明：按照题面描述的计算规则得到的不同结果数量。
输入说明：
1 1 1 1
输出说明：
5
样例说明：五个不同的计算结果分别为，0,1,2,3,4。 */