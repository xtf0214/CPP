#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char A[100];
    bool flag = true;
    cin >> A;
    int l = strlen(A);
    if (A[0] == '0' && l == 1)
    {
        cout << 0 << endl;
        return 0;
    } //0特殊，单独讨论
    if (A[0] == '-')
        cout << A[0]; //负数特殊，单独讨论
    for (int i = l - 1; i >= (A[0] == '-') ? 1 : 0; i--)
    {
        if (A[i] == '0' && flag)
            continue;
        if (A[i] != '0')
            flag = false;
        cout << A[i];
    }
    return 0;
}