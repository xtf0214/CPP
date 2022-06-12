#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000 + 5;
void f(int x, int s)
{
    if (x == 0)
    {
        cout << s << endl;
        return;
    }
    for (int i = x; x >= 1; x--)
        f(x - i, s * 10 + i);
}
int main()
{
    int x;
    cin >> x;
    f(x, 0);
    return 0;
}