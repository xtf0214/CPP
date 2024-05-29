/**
 * @file    :   FunctionPtrArray
 * @author  :   Tanphoon
 * @date    :   2024/05/27 14:00
 * @version :   2024/05/27 14:00
 */
#include <iostream>
using namespace std;

int _plus(int a, int b) { return a + b; }
int _minus(int a, int b) { return a - b; }
int _multi(int a, int b) { return a * b; }

int (*f[128])(int, int) = {};

int main() {
    f['+'] = _plus;
    f['-'] = _minus;
    f['*'] = _multi;
    
    cout << f['+'](1, 2) << '\n';
    cout << f['-'](1, 2) << '\n';
    cout << f['*'](1, 2) << '\n';
}
