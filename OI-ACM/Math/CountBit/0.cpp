#include <iostream>
using namespace std;
int count0(int x)
{
    int res = 0;
    while (x)
    {
        // 减去低位1
        x -= (-x & x);
        res++;
    }
    return res;
}
int count1(int x)
{
    int res = 0;
    while (x)
    {
        res += x & 1;
        x >>= 1;
    }
    return res;
}
int count2(int x)
{
    int res = 0;
    while (x)
    {
        // 去掉低位1的结果
        x = x & (x - 1);
        res++;
    }
}
