#include <bits/stdc++.h>
using namespace std;
char next(char x)
{
    if ('A' <= x && x <= 'Z')
        return (x - 'A' + 1) % 26 + 'A';
    else if ('a' <= x && x <= 'z')
        return (x - 'a' + 26 - 1) % 26 + 'a';
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        bool is_right = true;
        for (int i = 1; i < s.size(); i++)
        {
            if ('A' <= s[i - 1] && s[i - 1] <= 'Z')
            {
                if (!(s[i] == s[i - 1] - 'A' + 'a' || s[i] == next(s[i - 1])))
                {
                    is_right = false;
                    break;
                }
            }
            else if ('a' <= s[i - 1] && s[i - 1] <= 'z')
                if (!(s[i] == s[i - 1] - 'a' + 'A' || s[i] == next(s[i - 1])))
                {
                    is_right = false;
                    break;
                }
        }
        is_right ? printf("Y\n") : printf("N\n");
    }
    return 0;
}