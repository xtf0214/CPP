#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000 + 5;
void f(int x, int s, int st)
{
    if (x == 0)
    {
        cout << s << endl;
        return;
    }
    for (int i = min(st, x); i >= 1; i--)
        f(x - i, s * 10 + i, i);
}
int main()
{
    int x;
    cin >> x;
    f(x, 0, x);
    return 0;
}