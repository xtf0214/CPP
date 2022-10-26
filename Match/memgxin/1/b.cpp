#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a = 0, b = 0;
    cin >> n;
    string A, B;
    cin >> A >> B;
    for (int i = 0, l = A.size(); i < l - 1;)
        if (A[i] == A[i + 1])
            i += 2, a++;
        else
            i++;
    for (int i = 0, l = B.size(); i < l - 1;)
        if (B[i] == B[i + 1])
            i += 2, b++;
        else
            i++;
    cout << n - 2 * a << endl;
    if (n - 2 * a < n - 2 * b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}