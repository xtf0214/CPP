#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x = 0, y = 0;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
};

struct Circle {
    double x = 0, y = 0, r = 0;
    Circle() {}
    Circle(double x, double y, double r) : x(x), y(y), r(r) {}
};
void solve() {
    double x1, y1, x2, y2;
    double x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    double r1 = hypot((x2 - x1), (y2 - y1)) / 2;
    double r2 = hypot((x4 - x3), (y4 - y3)) / 2;
    Circle C1{(x1 + x2) / 2, (y1 + y2) / 2, r1};
    Circle C2{(x3 + x4) / 2, (y3 + y4) / 2, r2};
    double d = abs(C1.x - C2.x) + abs(C1.y - C2.y);
    double ans = d - sqrt(2.0) * C2.r;
    cout << setprecision(8) << ans <<'\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
        solve();
}