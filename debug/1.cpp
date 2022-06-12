#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 0; i <= (a - 1) * b; i++, cout << endl)
        for (int j = 0; j < a; j++)
            (i % (a - 1) == j || i % (a - 1) + j == a - 1) ? (cout << "x") : (cout << " ");
    return 0;
}