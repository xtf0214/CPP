#include <iostream>
using namespace std;
int count0(int x)
{
    int res = 0;
    while (x)
    {
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