#include <iostream>
#include <algorithm>
using namespace std;
int A[1005], B[1005]; //A[n],B[n+1]
int l, m, n;
int main()
{
    cin >> l >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (i)
            B[i] = A[i] - A[i - 1];
    }
    B[0] = A[0];
    B[n] = l - A[n - 1];
    sort(B, B + n + 1, greater<int>());
    if (m == 1)
    {
        int k = B[0] / 2;
        k = B[0] - k;
        cout << max(k, B[1]);
    }
    else if (m == 2)
    {
        int k = B[0] / 2;
        k = B[0] - 2 * k;
        cout << max(k, B[1]);
    }
    return 0;
}
/* 
小张想要通过一条宽为L的河（过河路线可视为一条直线），河里现有N个柱子，小张从起点出发（视为一维坐标0点），跳跃到相邻的柱子上。但是小李想让小张更加轻松过河，所以他准备悄悄增加M个柱子（必须加在整数坐标上），使得他跳跃的最大距离变小。现在小李想知道怎么增加才能使得小张需要跳跃的最大距离最小，输出最小值。
输入说明：第一行输入三个正整数L, N和M。其中L<1e9; M<N<1e4，接下来N行，每行一个正整数，表示柱子的坐标。
输出说明：一个整数，表示小张需要跳跃最大距离的最小值。
输入样例：
25 5 2
2
11
13
17
21
输出样例：
4 */