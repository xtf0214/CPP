#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// op|1:+|2:*|3:↑|4:↑↑
ll BigCalc(int op, ll num, ll time)
{
    if (op == 1)
        return num + time;
    ll temp = num;
    for (int i = 0; i < time - 1; i++)
        temp = BigCalc(op - 1, temp, num);
    return temp;
}
int main()
{
    cout << BigCalc(4, 2, 6);
    return 0;
}