// 7-28 黑洞数
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i = 1;
    cin >> n;
    do
    {
        int p, q;
        int a[3] = {n % 10, n / 10 % 10, n / 100 % 10};
        sort(a, a + 3);
        p = a[2] * 100 + a[1] * 10 + a[0];
        q = a[0] * 100 + a[1] * 10 + a[2];
        printf("%d: %d - %d = %d\n", i++, p, q, p - q);
        n = p - q;
    } while (n != 495);
}