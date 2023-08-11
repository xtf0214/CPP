#include <iostream>
#include <vector>
using namespace std;
int extgcd(int a, int b, int &x, int &y) {
    int d;
    if (b == 0)
        x = 1, y = 0, d = a;
    else {
        d = extgcd(b, a % b, y, x); // x'  y'
        y -= a / b * x;             // y = y - a / b * x = x' - a / b * y' = y'' - a / b * y'
    }
    printf("%dx+%dy==%d\nx==%d    y==%d\n\n", a, b, d, x, y);
    return d;
}
pair<int, int> extgcd(int a, int b) {
    if (b == 0)
        return {1, 0};
    else {
        auto [x, y] = extgcd(b, a % b);
        return {y, x - a / b * y};
    }
}
pair<int, int> ext_gcd(int a, int b) {
    int A[100] = {0}, d[100] = {0}, n = 0;
    while (b != 0) {
        int r = a % b;
        d[n++] = a / b;
        a = b, b = r;
    }
    A[n] = 0, A[n + 1] = 1;
    d[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        A[i] = A[i + 2] - A[i + 1] * d[i];
    return {A[1], A[0]};
}
int main() {
    // ax + by = 1
    cout << 167 / -166;
    int a, b, x, y;
    cin >> a >> b;
    extgcd(a, b, x, y);
    cout << x << " " << y << endl;
    auto [p, q] = extgcd(a, b);
    cout << p << " " << q;
    return 0;
}
/*
1x+0y==1
x==1    y==0

-166x+1y==1
x==0    y==1

167x+-166y==1
x==1    y==1

-834x+167y==1
x==1    y==5

1001x+-834y==1
x==5    y==6

-3837x+1001y==1
x==6    y==23

1001x+-3837y==1
x==23    y==6

23 6
23 6
 */