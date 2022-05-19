#include <windows.h>
#include <iostream>
using namespace std;
void fun()
{

}
int main()
{
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);

    fun(); //需计时的函数

    QueryPerformanceCounter(&t2);
    double time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;
    cout << "time = " << time << endl; //输出时间（单位：ｓ）
}