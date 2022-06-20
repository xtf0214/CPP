#include <iostream>
using namespace std;
int Month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int B[18] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char Q[12] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
char A[18];
int main()
{
    int year;
    int s = 0;
    cin >> A;

    year = (A[6] - '0') * 1000 + (A[7] - '0') * 100 + (A[8] - '0') * 10 + (A[9] - '0');
    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
        Month[2] = 29;
    else
        Month[2] = 28;
    for (int i = 0; i < 17; i++)
    {
        if (A[i] == '*')
            continue;
        int t = A[i] - '0';
        s += t * B[i];
    }
    int a = 0, b, c, d;
    for (int M = 1; M <= 12; M++)
    {
        a = M / 10, b = M % 10;
        for (int D = 1; D <= Month[M]; D++)
        {
            c = D / 10, d = D % 10;
            int t = (s + a * 7 + b * 9 + c * 10 + d * 5) % 11;
            if (Q[t] == A[17])
                cout << a << b << c << d << endl;
        }
    }
    return 0;
}