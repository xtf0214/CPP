/**
 * @file    :   FunctionPtr
 * @author  :   Tanphoon
 * @date    :   2024/05/27 14:00
 * @version :   2024/05/27 14:00
 */
#include <iostream>
using namespace std;

int a[3]{1, 2, 3};

int f(int a, int b) { return a + b; }

int *h(int i) { return i < 3 ? a + i : nullptr; } // 指针函数

int main() {
    int (*g)(int, int) = f; // 函数指针
    cout << g(1, 2) << '\n';

    cout << *h(2) << '\n';
}