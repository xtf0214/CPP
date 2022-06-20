// 7-54 孤单的数
#include <bits/stdc++.h>
using namespace std;
string a[100010], str;
int main()
{
    int n = 0, fg = 0;
    while (cin >> str)
    {
        if (str != " ")
            a[n++] = str;
        char ch = getchar();
        if (ch == '\n')
            break;
    }
    sort(a, a + n); //排序
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[i + 1])
            i++;
        else
        {
            if (fg == 0)
            {
                cout << a[i] << " ";
                fg++;
                continue;
            }
            else if (fg == 1)
            {
                cout << a[i];
                break;
            }
        }
    }
    return 0;
}
