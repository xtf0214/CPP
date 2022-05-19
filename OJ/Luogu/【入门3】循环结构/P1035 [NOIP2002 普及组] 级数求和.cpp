#include <iostream>
using namespace std;
int main()
{
    int i = 0;
    double k, s = 0;
    cin >> k;
    while (s <= k)
    {
        i++;
        s += 1.0 / i;
    }
    cout << i;
    return 0;
}