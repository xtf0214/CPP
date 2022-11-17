// 7-2 判断是否构成三角形
#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a)
        printf("YES");
    else
        printf("NO");
    return 0;
}