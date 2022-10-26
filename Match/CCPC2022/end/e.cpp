#include <bits/stdc++.h>
using namespace std;

char getHaiku(int len)
{
    char ch;
    char ch_set[128] = {0};
    while ((ch = cin.get()) != EOF)
    {
        if (++ch_set[ch] == len)
        {
            return ch;
        }
    }
    return 0;
}

int main()
{
    int num;
    cin >> num;
    if (num < 17)
    {
        cout << "none";
        return 0;
    }
    cin.get();
    char c[3] = {0};
    c[0] = getHaiku(5);
    c[1] = getHaiku(7);
    c[2] = getHaiku(5);

    if (c[2])
    {
        cout << c[0];
        cout << c[0];
        cout << c[0];
        cout << c[0];
        cout << c[0];
        cout << c[1];
        cout << c[1];
        cout << c[1];
        cout << c[1];
        cout << c[1];
        cout << c[1];
        cout << c[1];
        cout << c[2];
        cout << c[2];
        cout << c[2];
        cout << c[2];
        cout << c[2];
    }
    else
    {
        cout << "none";
    }
    return 0;
}