#include <iostream>
using namespace std;
int main()
{
    int m, n;
    long long squares = 0, rectangles = 0;
    cin >> n >> m;
    if (m > n)
        swap(m, n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                squares += (m - i + 1) * (n - i + 1);
            else
                rectangles += (m - i + 1) * (n - j + 1);
        }
    cout << squares << " " << rectangles;
    return 0;
}