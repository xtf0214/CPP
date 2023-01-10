#include <iostream>
using namespace std;
int main()
{
    int i = 0;
    double k, s = 0, t = 2;
    cin >> k;
    while (s <= k)
    {
        s += t;
        i++;
        t = t * 0.98;
    }
    cout << i;
    return 0;
}