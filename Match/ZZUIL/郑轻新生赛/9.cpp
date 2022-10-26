#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int T, a, b, s = 0;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &a, &b);
        s = 0;
        while (gcd(a + s, b) == 1)
            s++;
        cout << s << endl;
    }
    return 0;
}