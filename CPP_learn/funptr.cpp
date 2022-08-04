#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }

int (*pf)(int, int); //函数指针，指向函数的指针，类型为int(*)(int, int)

int *fp() { return NULL; } //指针函数，返回值为指针的函数，类型为int*

int main()
{
    pf = add;
    cout << pf(1, 2);
    cout << fp();

    int A[10];

    int *pA[10]; //指针数组,存放指针的数组，类型为

    int (*Ap)[10]; //数组指针，指向数组的指针

}