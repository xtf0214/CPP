#include <iostream>
using namespace std;
int main()
{
    int i = 0, x, n, p, q, s;
    cin >> x >> n;
    p = n / 7;
    q = n % 7;
    s = 250 * 5 * p;
    for (i = 0; i < q; i++)
    {
        if ((x + i) % 7 == 6 || (x + i) % 7 == 0)
            continue;
        s += 250;
    }
    cout << s;
    return 0;
}
