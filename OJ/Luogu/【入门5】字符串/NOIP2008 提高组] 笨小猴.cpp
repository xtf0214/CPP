#include <iostream>
#include <cstring>
using namespace std;
bool Prime(int x)
{
    if (x == 0 || x == 1)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
int main()
{
    int S[27] = {0}, minimun = 10000, maximun = 1;
    char A[101];
    cin >> A;
    for (int i = 0; i < strlen(A); i++)
        S[A[i] - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        if (S[i] == 0)
            continue;
        minimun = min(minimun, S[i]);
        maximun = max(maximun, S[i]);
    }
    if (Prime(maximun - minimun))
        cout << "Lucky Word" << endl
             << maximun - minimun;
    else
        cout << "No Answer" << endl
             << 0;
    return 0;
}