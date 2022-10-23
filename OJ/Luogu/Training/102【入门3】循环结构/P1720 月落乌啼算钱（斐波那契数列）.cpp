#include <iostream>
using namespace std;
int main()
{
    long long A[50] = {0};
    int n;
    A[1] = A[2] = 1;
    cin >> n;
    for (int i = 3; i <= n; i++)
        A[i] = A[i - 1] + A[i - 2];
    cout << A[n] << ".00" << endl;
    return 0;
}