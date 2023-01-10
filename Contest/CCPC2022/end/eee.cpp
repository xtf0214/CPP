#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    char ch;
    cin >> n;
    cin >> s;
    if(n<17)
    {
        cout << "none";
        return 0;
    }
    char c[4]{0};
    int cnt[128]{0};
    int len[4] = {0, 5, 7, 5};
    int st = 0;

    for (int i = 1; i <= 3; i++)
    {
        memset(cnt, 0, sizeof(cnt));
        for (int j = st; j < n; j++)
        {
            ch = s[j];
            cnt[ch]++;
            if (cnt[ch] == len[i])
            {
                c[i] = ch;
                st = j;
                break;
            }
        }
    }
    if (c[3] == 0)
    {
        cout << "none";
    }
    else
    {
        for (int i = 0; i < 5; i++)
            cout << c[1];
        for (int i = 0; i < 7; i++)
            cout << c[2];
        for (int i = 0; i < 5; i++)
            cout << c[3];
    }

    return 0;
}