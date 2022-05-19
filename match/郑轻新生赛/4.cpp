#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int n, rank = 0;
    char s[9] = "00000000";
    cin >> n >> a;
    for (int i = 0; i < a.size(); i += 3)
    {
        int res = 0;
        for (int j = 2; j >= 0; j--)
            res = res * 2 + a[i + j] - '0';
        if (s[res] == '0')
        {
            s[res] = 'a' + rank;
            rank++;
        }
        cout << s[res];
    }
    return 0;
}