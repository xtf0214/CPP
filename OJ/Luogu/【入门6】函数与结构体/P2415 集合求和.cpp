#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n = 0, a;
    long long s = 0;
    while (cin >> a)
        s += a, n++;
    s *= pow(2, n - 1);
    cout << s;
    return 0;
}