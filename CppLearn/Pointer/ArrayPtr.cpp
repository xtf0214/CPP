/**
 * @file    :   ArrayPtr
 * @author  :   Tanphoon
 * @date    :   2024/05/27 14:00
 * @version :   2024/05/27 14:00
 */
#include <iostream>
using namespace std;

int a[3]{1, 2, 3};

void print(int *a, int n) {
    // 数组指针，一个指向大小为n的数组的指针
    int(*b)[n] = (int(*)[n])a;
    for (int i = 0; i < n; i++)
        cout << (*b)[i] << ' '; 
    cout << '\n';
}

int main() {
    int *b[3]; // 指针数组，存储了多个指针的数组
    for (int i = 0; i < 3; i++)
        b[i] = a + i;
    for (int i = 0; i < 3; i++)
        cout << *b[i] << ' ';
    cout << '\n';
    
    print(a, 3);
}