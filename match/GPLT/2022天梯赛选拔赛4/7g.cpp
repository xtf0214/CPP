#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int k = 1, sum = 0;
    for (int i = 0; i < s.size() - 1; i++)
        if (s[i] != '-')
            sum += (s[i] - '0') * k++;
    sum %= 11;
    if (sum == s[s.size() - 1] - '0' || (sum == 10 && s[s.size() - 1] == 'X'))
        cout << "right";
    else
    {
        s[s.size() - 1] = (sum == 10) ? 'X' : sum + '0';
        cout << s;
    }
    return 0;
}
