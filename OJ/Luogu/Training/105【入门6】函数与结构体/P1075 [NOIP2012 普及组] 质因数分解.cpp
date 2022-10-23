#include <iostream>
using namespace std;
int main()
{
    long long x;
    cin >> x;
    for (int i = 2; i <= x; i++)
        if (x % i == 0)
        {
            cout << x / i << endl;
            return 0;
        }
}