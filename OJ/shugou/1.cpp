#include <iostream>
using namespace std;
void Swap1(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void Swap2(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void Swap3(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int a, b;
    a = 5;
    b = 9;
    Swap2(a, b);
    printf("a=%d,b=%d\n", a, b);
    return 0;
}