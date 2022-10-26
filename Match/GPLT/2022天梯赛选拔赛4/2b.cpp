#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, s1;
    getline(cin, s);
    for (char ch : s)
        if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'))
            cout << ch;
    return 0;
}