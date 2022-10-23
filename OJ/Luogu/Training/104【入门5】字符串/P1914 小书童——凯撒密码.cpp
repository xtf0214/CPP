#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n, l;
    char A[51];
    cin >> n >> A;
    l = strlen(A);
    n %= 26;
    for (int i = 0; i < l; i++)
        cout << (char)((A[i] + n > 'z') ? A[i] + n - 26 : A[i] + n);
    return 0;
}