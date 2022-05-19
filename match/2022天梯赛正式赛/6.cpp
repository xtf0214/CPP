#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    string t1, t2;
    cin >> s1 >> s2;
    for (int i = 1; i < s1.size(); i++)
        if ((s1[i] - '0') % 2 == (s1[i - 1] - '0') % 2)
            t1 += max(s1[i], s1[i - 1]);
    for (int i = 1; i < s2.size(); i++)
        if ((s2[i] - '0') % 2 == (s2[i - 1] - '0') % 2)
            t2 += max(s2[i], s2[i - 1]);
    if (t1 == t2)
        cout << t1;
    else
        cout << t1 << endl
             << t2;
    return 0;
}