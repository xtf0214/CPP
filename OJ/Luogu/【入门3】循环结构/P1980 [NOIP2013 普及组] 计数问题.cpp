#include <iostream>
using namespace std;
int main()
{
    long long n, i, x, b, a, t = 0;
    cin >> n >> x;
    for (i = 1; i <= n; i++)
    {
        b = i;
        while (b != 0)
        {
            a = b % 10;
            b = b / 10;
            if (a == x)
                t++;
        }
    }
    cout << t << endl;
    return 0;
}