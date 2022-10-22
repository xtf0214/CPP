#include <iostream>
using namespace std;
int main()
{
    int A[1000] = {0}, m, t, n;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        A[t]++;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < A[i]; j++)
            cout << i << " ";
    return 0;
}