#include <bits/stdc++.h>
using namespace std;
int count(int x)
{
    int s = 0;
    while (x)
        s += x % 10, x /= 10;
    return s;
}
int main()
{
    int n;
    int x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        bool is_chuxin = true;
        int bf = count(x);
        for (int i = 2; i <= 9; i++)
            if (count(x * i) != bf)
            {
                is_chuxin = false;
                break;
            }
        is_chuxin ? printf("%d\n", bf) : printf("NO\n");
    }
    return 0;
}