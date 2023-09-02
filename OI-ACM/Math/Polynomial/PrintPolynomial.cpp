#include <bits/stdc++.h>
using namespace std;
using Poly = vector<int>;
void NumberOut(double a, int i, int n) {
    if (a == 0)
        return;
    if (i != n && a > 0)
        cout << "+";
    if (a != 1 || a != -1)
        cout << a;
    if (a == -1)
        cout << "-";
    if (i > 1)
        cout << "x^" << i;
    if (i == 1)
        cout << "x";
}
void printPoly(const Poly &P) {
    for (int i = P.size() - 1; i >= 0; i--)
        NumberOut(P[i], i, P.size() - 1);
}
int main() {
    Poly a{0, -2, 3, -4};
    printPoly(a);
}