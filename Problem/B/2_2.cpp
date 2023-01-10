#include <iostream>
using namespace std;
int n, A[2000005];
bool Book[2000005];
int main()
{
    int cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        if (A[i] % (i + 1 - cnt) == 0)
        {
            Book[i] = true;
            cnt++;
        }
    }
    for (int i = 1; i <= n; i++)
        if (!Book[i])
            cout << A[i] << " ";
}