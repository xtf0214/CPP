#include <bits/stdc++.h>
using namespace std;

long long a[505], b[505], c[505];

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(c, 0, sizeof(c));
        string sa, sb;
        cin >> sa >> sb;
        for (int i = 1; i <= sa.size(); i++)
            a[i] = sa[sa.size() - i] - '0';
        for (int i = 1; i <= sb.size(); i++)
            b[i] = sb[sb.size() - i] - '0';
        for (int i = 1; i <= sa.size(); i++)
            for (int j = 1; j <= sb.size(); j++)
                c[i + j - 1] += a[i] * b[j];
        int len = 500;
        for (int i = 1; i <= len; i++)
            c[i + 1] += c[i] / 10, c[i] %= 10;
        while (c[len] == 0)
            len--;
        for (int i = len; i >= 1; i--)
            cout << c[i];
        cout << endl;
    }
    return 0;
}