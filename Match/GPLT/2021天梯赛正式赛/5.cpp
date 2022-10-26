#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if (s.size() == 6)
    {
        printf("%c%c%c%c-%c%c", s[0], s[1], s[2], s[3], s[4], s[5]);
    }
    else if (s.size() == 4)
    {
        int y = (s[0] - '0') * 10 + (s[1] - '0');
        y = y < 22 ? 20 : 19;
        printf("%d%c%c-%c%c", y, s[0], s[1], s[2], s[3]);
    }
    return 0;
}