#include <bits/stdc++.h>
using namespace std;


signed main()
{
    string s;
    cin >> s;
    for (char &c : s)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            c = c - 'a' + 'A';
    cout << s;
    return 0;
}