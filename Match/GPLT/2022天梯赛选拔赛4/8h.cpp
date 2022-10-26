#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, s1;
    int k;
    getline(cin, s);
    for (int i = s.size() - 1; i >= 0;)
    {
        k = 0;
        if (s[i] == '#')
        {
            k = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            s1 += k + 'a' - 1;
            i -= 3;
        }
        else if (s[i] != ' ')
        {
            s1 += s[i] - '0' + 'a' - 1;
            i--;
        }
        else
        {
            s1 += ' ';
            i--;
        }
    }
    for (int i = s1.size() - 1; i >= 0; i--)
        cout << s1[i];
    return 0;
}
