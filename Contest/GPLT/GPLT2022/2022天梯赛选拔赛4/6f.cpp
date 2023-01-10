#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < 4; i++)
    {
        int sum = 0;
        for (int j = 0; j < 8; j++)
            sum += (s[i * 8 + j] - 48) << (7 - j);
        printf("%c%d", "."[!i], sum);
    }
    return 0;
}

