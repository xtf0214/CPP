// 7-3	一维数组的动态和
#include <iostream>
using namespace std;
int main()
{
    int n, s = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        cout << s << " ";
    }
    return 0;
}