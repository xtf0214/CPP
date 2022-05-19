#include <iostream>
using namespace std;
int n, a, s = 0;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a / 2 % 2 == 1 && a / 1 % 2 == 0)
            s++;
    }
    cout << s;
    return 0;
}
/* a / 1 % 2 //声音
a / 2 % 2 //显示
a / 4 % 2 //鼠标
a / 8 % 2 //键盘 */