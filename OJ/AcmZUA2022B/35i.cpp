// 1121 Problem  i	闹铃何时会响？
#include <bits/stdc++.h>
using namespace std;
int main() {
    int ct, tt;
    cin >> ct >> tt;
    if (tt - ct < 0)
        cout << tt - ct + 24;
    else
        cout << tt - ct;
    return 0;
}