#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int n = 1, a, t, B[1005] = {0};
    cin >> n >> a;
    for (int i = 1; i < n; i++)
    {
        cin >> t;
        B[i] = abs(t - a);
        a = t;
    }
    sort(B + 1, B + n);
    for (int i = 2; i < n; i++)
        if (B[i] - B[i - 1] != 1)
        {
            cout << "Not jolly" << endl;
            return 0;
        }
    cout << "Jolly" << endl;
    return 0;
}