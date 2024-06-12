/**
 * @file    :   E
 * @author  :   Tanphoon
 * @date    :   2024/06/08 13:01
 * @version :   2024/06/08 13:01
 * @link    :   https://ac.nowcoder.com/acm/contest/84773/E
 */
#include <bits/stdc++.h>
using namespace std;
namespace Geometry {
using ld = long double;
ld pi = acos(-1);
ld eps = 1e-8;
int sgn(ld x) { return (x > eps) - (x < -eps); }
ld norm(ld x) { return sgn(x) ? x : 0; }
ld toRad(ld d) { return d * pi / 180; }
struct Line;
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
    Vector unitVec() { return *this / len(); }
    ld len() { return sqrt(*this * *this); }  // 欧几里得距离
    ld len2() { return *this * *this; }       // 欧几里得距离(不开方)
    ld lenM() { return abs(x) + abs(y); }     // 曼哈顿距离
    Vector rotate() { return Vector(-y, x); } // 逆时针旋转90
    Vector rotate(ld rad) {                   // 逆时针旋转rad
        return Vector(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
    }
    int direction() { // [0,pi)->1, [pi,2*pi)->-1
        return y > 0 || (sgn(y) == 0 && x > 0) ? 1 : -1;
    }
    friend istream &operator>>(istream &is, Vector &p) { return is >> p.x >> p.y; }
    friend ostream &operator<<(ostream &os, Vector &p) {
        return os << "(" << norm(p.x) << ", " << norm(p.y) << ")";
    }
    // 点与直线
    int PointLineRelation(Line l); // 0: on, 1: left, -1: right
    bool onSegment(Line l);
    ld PointLineDist(Line l);
    Vector PointLineProj(Line l);
};
// Vector
ld angle1(Vector a, Vector b) { return acos(a * b / a.len() / b.len()); } // 夹角
ld angle2(Vector a, Vector b) { return abs(atan2(abs(a ^ b), a * b)); }   // 夹角
bool parallel(Vector a, Vector b) { return sgn(a ^ b) == 0; }             // 平行
bool vertical(Vector a, Vector b) { return sgn(a * b) == 0; }             // 垂直
// Line
struct Line {
    Vector a, b;
    Line(Vector a_ = Vector(), Vector b_ = Vector()) : a(a_), b(b_) {}
    friend ostream &operator<<(ostream &os, Line l) {
        return os << "<" << l.a << ", " << l.b << ">";
    }
};
using Segment = Line;
int Vector::PointLineRelation(Line l) { return sgn((l.b - l.a) ^ (*this - l.a)); }
bool Vector::onSegment(Line l) {
    return sgn((l.b - l.a) ^ (*this - l.a)) == 0 && sgn((l.a - *this) * (l.b - *this)) <= 0;
}
ld Vector::PointLineDist(Line l) { return abs((l.b - l.a) ^ (*this - l.a)) / (l.b - l.a).len(); }
Vector Vector::PointLineProj(Line l) {
    return l.a + (l.b - l.a) * ((*this - l.a) * (l.b - l.a)) / (l.b - l.a).len2();
}
int lineRelation(Line l1, Line l2) { // 0: 平行 1: 重合 2: 相交
    if (sgn((l2.b - l2.a) ^ (l1.b - l1.a)))
        return (l1.a.PointLineRelation(l2) == 0) ? 1 : 0;
    return 2;
}
}; // namespace Geometry
using namespace Geometry;
inline void solve() {
    Vector a[4], b[4];
    cin >> a[0] >> a[2] >> b[0] >> b[2];
    a[1] = a[0] + (a[2] - a[0]).rotate(toRad(-45)) * cos(toRad(45));
    a[3] = a[0] + (a[2] - a[0]).rotate(toRad(45)) * cos(toRad(45));
    b[1] = b[0] + (b[2] - b[0]).rotate(toRad(-45)) * cos(toRad(45));
    b[3] = b[0] + (b[2] - b[0]).rotate(toRad(45)) * cos(toRad(45));
    int same = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (a[i] == b[j])
                same++;
    if (same == 1) {
        cout << "Infinity" << '\n';
        return;
    }
    Line lineA[4], lineB[4];
    for (int i = 0; i < 4; i++) {
        lineA[i] = Line(a[i], a[(i + 1) % 4]);
        lineB[i] = Line(b[i], b[(i + 1) % 4]);
    }
    bool intersect = false;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (a[i].onSegment(lineB[j]) || b[i].onSegment(lineA[j]))
                intersect = true;
    if (!intersect) {
        cout << 4 << '\n';
    } else {
        cout << 3 << '\n';
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