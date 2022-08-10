#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int main()
{
    string s, ss, res;
    int f = 0, a = 0, b = 0;
    char c, x;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '=')
        {
            f = 1;
            continue;
        }
        if ((i == 0 && s[i] != '-') || (s[i - 1] == '=' && s[i] != '-'))
            ss += f ? '-' : '+';
        if (s[i] == '+' || s[i] == '-')
            ss += f ? '-' + '+' - s[i] : s[i];
        else
            ss += s[i];
    }
    for (int i = 0;; i++)
    {
        if (ss[i] == '+' || ss[i] == '-' || i == ss.size())
        {
            if (i)
                c ? a += atoi(res.c_str()) *f : b += atoi(res.c_str()) * f;
            if (i == ss.size())
                break;
            res.clear();
            c = 0;
            f = ss[i] == '+' ? 1 : -1;
        }
        else if ('a' <= ss[i] && ss[i] <= 'z')
        {
            c = ss[i];
            x = c;
            continue;
        }
        else
            res += ss[i];
    }
    printf("%c=%.3lf", x, -double(b) / a);
    return 0;
}