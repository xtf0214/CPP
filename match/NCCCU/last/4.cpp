#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
using namespace std;
struct List
{
    string key;
    int num, x, y;
    double dist;
    List(string &_key, int &_num, int &_x, int &_y)
    {
        key = _key, num = _num, x = _x, y = _y;
    }
    List() {}
} C[505], S[505];
bool cmp1(List a, List b) { return a.key > b.key; }
bool cmp2(List a, List b) { return a.num < b.num; }
int lc, ls;
int main()
{
    string key;
    char type;
    int num, x, y;
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> key >> type >> num >> x >> y;
        if (type == 'C')
            C[lc++] = List(key, num, x, y);
        else if (type == 'S')
            S[ls++] = List(key, num, x, y);
    }
    sort(C, C + n, cmp1);
    sort(S, S + n, cmp1);
    for (int i = 0; i < n; i++)
        C[i].dist = sqrt((C[i].x - S[i].x) * (C[i].x - S[i].x) + (C[i].y - S[i].y) * (C[i].y - S[i].y));
    sort(C, C + n, cmp2);
    sort(S, S + n, cmp2);
    for (int i = 0; i < n; i++)
        printf("%010d %010d %.2lf\n", C[i].num, S[i].num, C[i].dist);
    return 0;
}
/* 
小A拿到了一个文档，文档中记录了N条客户端信息和N条服务端信息（信息内容含校验位、类型、编号和虚拟位置坐标），但是这些信息之间并没有相互配对。小A现在需要将所有的信息两两配对（已知所有数据都可以配对），配对的条件为某个客户端的校验位和某个服务器端的校验位相同。请输出每一对客户端服务器端的编号，以及客户端和服务器之间虚拟位置的距离（虚拟位置距离根据平面坐标直线距离计算，保留两位小数，四舍五入），按照每一对中的客户端编号由小到大依次输出。
输入说明：第一行是一个整数N，之后2N行是文档中的信息，每行一条。每条信息包括以下几个元素：校验位（一个8位字符串），类型（客户端还是服务器端，C表示客户端，S表示服务器端），编号（一个8位整数），虚拟位置（可以认为是一个整数的二维坐标）。(N≤1e3)
输出说明：输出N个匹配结果，每行一对匹配信息（分别为客户端编号，服务器端编号和距离值，以空格分隔）。
输入样例：
2
abcdefgh C 00000001 1 1
abcdefgi C 00000002 1 3
abcdefgh S 00000003 0 0
abcdefgi S 00000004 2 3
输出样例：
00000001 00000003 1.41
00000002 00000004 1.00 */