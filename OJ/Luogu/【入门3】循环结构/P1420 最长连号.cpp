#include <iostream>
using namespace std;
int main()
{
    long long a, b;
    int n, maxn = 1, t = 1; //一个数也是连号
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (i == 0)
        {
            b = a;
            continue;
        }
        if (a - b == 1)
            t++;    //数列递增1，计入一次
        else
        {
            maxn = max(t, maxn);    //出现非递增1，进行结算
            t = 1;  //一个数也是连号
        }
        b = a;
    }
    cout << maxn << endl;
    return 0;
}