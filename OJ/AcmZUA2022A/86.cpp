#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, s1;
    bool used[128];
    fill(used, used + 128, false);
    getline(cin, s);
    for (char i : s)
        if ('A' <= i && i <= 'Z')
            if (!used[i])
            {
                s1 += i;
                used[i] = true;
            }
    if (s1.empty())
        cout << "Not Found";
    else
        cout << s1;
    return 0;
}