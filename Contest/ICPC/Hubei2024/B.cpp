/**
 * @file    :   B
 * @author  :   Tanphoon
 * @date    :   2024/09/16 15:06
 * @version :   2024/09/16 15:06
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include <DEBUG.h>
#else
#define debug(...) 0
#endif
const int N = 1e6 + 5;
#include <bits/stdc++.h>
using namespace std;
namespace Geometry {
using ld = long double;
ld pi = acos(-1);
ld eps = 1e-8;
int sgn(ld x) { return (x > eps) - (x < -eps); }
ld norm(ld x) { return sgn(x) ? x : 0; }
ld toRad(ld d) { return d * pi / 180; }
// Point
struct Vector {
    ld x, y;
    Vector(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
    Vector operator-() const { return Vector(-x, -y); }
    friend Vector operator+(Vector a, Vector b) { return Vector(a.x + b.x, a.y + b.y); }
    friend Vector operator-(Vector a, Vector b) { return Vector(a.x - b.x, a.y - b.y); }
    friend Vector operator*(Vector a, ld b) { return Vector(a.x * b, a.y * b); }
    friend Vector operator*(ld a, Vector b) { return Vector(a * b.x, a * b.y); }
    friend Vector operator/(Vector a, ld b) { return Vector(a.x / b, a.y / b); }
    friend bool operator==(Vector a, Vector b) { return !sgn(a.x - b.x) && !sgn(a.y - b.y); }
    friend ld operator*(Vector a, Vector b) { return a.x * b.x + a.y * b.y; } // 点乘
    friend ld operator^(Vector a, Vector b) { return a.x * b.y - a.y * b.x; } // 叉乘
    Vector unitVec() { return *this / len(); }                                // 单位向量
    ld len() { return sqrt(*this * *this); }                                  // 欧几里得距离
    ld len2() { return *this * *this; }       // 欧几里得距离平方
    ld lenM() { return abs(x) + abs(y); }     // 曼哈顿距离
    Vector rotate() { return Vector(-y, x); } // 逆时针旋转90
    Vector rotate(ld rad) {                   // 逆时针旋转rad
        return Vector(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
    }
    // 向量的极角[0,pi)：1, [pi,2*pi)：-1
    int direction() { return y > 0 || (sgn(y) == 0 && x > 0) ? 1 : -1; }
    friend istream &operator>>(istream &is, Vector &p) { return is >> p.x >> p.y; }
    friend ostream &operator<<(ostream &os, Vector &p) {
        return os << "(" << norm(p.x) << ", " << norm(p.y) << ")";
    }
};
using Point = Vector;
// Vector
ld angle1(Vector a, Vector b) { return acos(a * b / a.len() / b.len()); } // 向量夹角
ld angle2(Vector a, Vector b) { return abs(atan2(abs(a ^ b), a * b)); }   // 向量夹角
bool parallel(Vector a, Vector b) { return sgn(a ^ b) == 0; }             // 向量平行
bool vertical(Vector a, Vector b) { return sgn(a * b) == 0; }             // 向量正交
// Line
struct Line {
    Vector a, b;
    Line(Vector a_ = Vector(), Vector b_ = Vector()) : a(a_), b(b_) {}
    friend ostream &operator<<(ostream &os, Line l) {
        return os << "<" << l.a << ", " << l.b << ">";
    }
};
using Segment = Line;
// 点和线的关系 0：在直线上 1：在直线左侧 -1：在直线右侧
int PointLineRelation(Point p, Line l) { return sgn((l.b - l.a) ^ (p - l.a)); }
// 点和线段的关系 0：在线段外 1：在线段上
bool PointOnSegment(Point p, Line l) {
    return sgn((l.b - l.a) ^ (p - l.a)) == 0 && sgn((l.a - p) * (l.b - p)) <= 0;
}
// 点到直线的距离
ld PointLineDist(Point p, Line l) { return abs((l.b - l.a) ^ (p - l.a)) / (l.b - l.a).len(); }
// 点在直线的投影
Point PointLineProj(Point p, Line l) {
    return l.a + (l.b - l.a) * ((p - l.a) * (l.b - l.a)) / (l.b - l.a).len2();
}
// 线线关系 0: 平行 1: 重合 2: 相交
int LineRelation(Line l1, Line l2) {
    if (sgn((l2.b - l2.a) ^ (l1.b - l1.a)))
        return (PointLineRelation(l1.a, l2) == 0) ? 1 : 0;
    return 2;
}
// 直线的交点
Vector lineIntersection(Line l1, Line l2) {
    assert(LineRelation(l1, l2) == 2);
    return l1.a +
           (l1.b - l1.a) * (((l2.b - l2.a) ^ (l1.a - l2.a)) / ((l2.b - l2.a) ^ (l1.a - l1.b)));
}
using Polygo = vector<Point>;
ld PolygonArea(const vector<Point> &a) {
    ld s = 0;
    for (int i = 0, n = a.size(); i < n; i++)
        s += (a[i] ^ a[(i + 1) % n]);
    return s / 2;
}
}; // namespace Geometry
using namespace Geometry;

inline void solve() {
    int n;
    cin >> n;
    vector<Point> a(n);
    for (auto &[x, y] : a)
        cin >> x >> y;
    ld res = INFINITY;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (!parallel(a[i] - a[j], a[k] - a[j])) {
                    res = min(res, abs(PolygonArea({a[i], a[j], a[k]})));
                }
    if (res == INFINITY) {
        cout << -1 << '\n';
    } else {
        cout << fixed << setprecision(10) << res << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}