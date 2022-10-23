#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int k;
    double t, d;
    cin >> k;
    t = ((-1 + sqrt(1 + 8 * k)) / 2);  //求t(t+1)/2=k的解t
    d = ceil(t); //向上取整
    if (t == d)
        cout << d * (d + 1) * (2 * d + 1) / 6; //恰好完成最后连续的几个
    else
        cout << (d - 1) * d * (2 * d - 1) / 6 + d * (k - (d - 1) * d / 2); //没有完成最后连续的几个
    return 0;
}