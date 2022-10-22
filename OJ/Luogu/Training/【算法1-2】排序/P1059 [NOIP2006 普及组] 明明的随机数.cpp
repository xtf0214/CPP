#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, A[105], B[105], s = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(A, A + n);
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1 && A[i] != A[i - 1])
        {
            B[s++] = A[i];
            break;
        }
        if (A[i] != A[i + 1])
            B[s++] = A[i];
    }
    cout << s << endl;
    for (int i = 0; i < s; i++)
        cout << B[i] << " ";
    return 0;
}