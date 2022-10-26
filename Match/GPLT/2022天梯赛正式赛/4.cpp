#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    long long mul = 1;
    cin >> a >> b;
    for (int i = 1; i <= a + b; i++)
        mul *= i;
    cout << mul;
    return 0;
}