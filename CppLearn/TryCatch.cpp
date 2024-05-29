#include <cstdlib>
#include <iostream>
using namespace std;

double fuc(double x, double y) {
    if (y == 0)
        throw y;
    return x / y;
}
int main() {
    double res;
    try {
        res = fuc(2, 3);
        cout << res << endl;
        res = fuc(4, 0);
        cout << res << endl;
    } catch (double) {
        cerr << "Error of dividing zero.\n";
        exit(1);
    }
    return 0;
}