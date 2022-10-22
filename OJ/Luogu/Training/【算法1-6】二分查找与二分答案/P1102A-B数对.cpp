#include <iostream>
#include <algorithm>
using namespace std;
int a[200005], n, c;
int main()
{
    cin >> n >> c;
    long long sum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        sum += upper_bound(a + i + 1, a + n, a[i] + c) - lower_bound(a + i + 1, a + n, a[i] + c);
    cout << sum;
    return 0;
}