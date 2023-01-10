#include <iostream>
using namespace std;
int main()
{
    int i, k = 1, s = 0, p;
    char a[15];
    for (i = 0; i < 13; i++)
    {
        if (i == 1 || i == 5 || i == 11)
            cin >> a[i];
        else
        {
            cin >> a[i];
            if (i == 12)
                break;
            s += (int)(a[i] - '0') * k++;
        }
    }
    if (a[12] == 'X')
        p = 10;
    else
        p = (int)(a[12] - '0');
    if (p == s % 11)
        cout << "Right";
    else
    {
        for (i = 0; i < 13; i++)
        {
            if (i == 12)
            {
                if (s % 11 == 10)
                    cout << "X";
                else
                    cout << s % 11;
                break;
            }
            cout << a[i];
        }
    }
}
