#include <iostream>
using namespace std;
int main() {
    int k = 1, s = 0, p, q;
    string a;
    cin >> a;
    for (int i = 0; i < 12; i++)
        if (i != 1 && i != 5 && i != 11)
            s += int(a[i] - '0') * k++;

    p = (a[12] == 'X') ? 10 : int(a[12] - '0');

    if (p == s % 11) {
        cout << "Right";
    } else {
        for (int i = 0; i < 12; i++)
            cout << a[i];
        if (s % 11 == 10)
            cout << "X";
        else
            cout << s % 11;
    }
}
