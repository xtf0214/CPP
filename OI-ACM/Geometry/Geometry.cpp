/**
 * @file    :   平面几何模板
 * @author  :   Tanphoon
 * @date    :   2024/06/11 18:16
 * @version :   2024/06/11 18:16
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
int pointLineRelation(Point p, Line l) { return sgn((l.b - l.a) ^ (p - l.a)); }
// 点和线段的关系 0：在线段外 1：在线段上
bool pointOnSegment(Point p, Line l) {
    return sgn((l.b - l.a) ^ (p - l.a)) == 0 && sgn((l.a - p) * (l.b - p)) <= 0;
}
// 点到直线的距离
ld pointLineDist(Point p, Line l) { return abs((l.b - l.a) ^ (p - l.a)) / (l.b - l.a).len(); }
// 点在直线的投影
Point pointLineProj(Point p, Line l) {
    return l.a + (l.b - l.a) * ((p - l.a) * (l.b - l.a)) / (l.b - l.a).len2();
}
// 线线关系 0: 平行 1: 重合 2: 垂直 3: 相交但不垂直
int lineRelation(Line l1, Line l2) {
    if (sgn((l2.b - l2.a) ^ (l1.b - l1.a)) == 0)
        return (pointLineRelation(l1.a, l2) == 0) ? 1 : 0;
    else if (sgn((l2.b - l2.a) * (l1.b - l1.a)) == 0)
        return 2;
    else
        return 3;
}
// 直线的交点
Vector lineIntersection(Line l1, Line l2) {
    assert(lineRelation(l1, l2) == 2);
    ld t = ((l2.b - l2.a) ^ (l1.a - l2.a)) / ((l2.b - l2.a) ^ (l1.a - l1.b));
    return l1.a + (l1.b - l1.a) * t;
}
// // 0 : 不相交
// // 1 : 普通相交
// // 2 : 重合
// // 3 : 交于端点
// tuple<int, Vector, Vector> segmentIntersection(Line l1, Line l2) {
//     if (max(l1.a.x, l1.b.x) < min(l2.a.x, l2.b.x)) {
//         return {0, Vector(), Vector()};
//     }
//     if (min(l1.a.x, l1.b.x) > max(l2.a.x, l2.b.x)) {
//         return {0, Vector(), Vector()};
//     }
//     if (max(l1.a.y, l1.b.y) < min(l2.a.y, l2.b.y)) {
//         return {0, Vector(), Vector()};
//     }
//     if (min(l1.a.y, l1.b.y) > max(l2.a.y, l2.b.y)) {
//         return {0, Vector(), Vector()};
//     }
//     if (((l1.b - l1.a) ^ (l2.b - l2.a)) == 0) {
//         if (((l1.b - l1.a) ^ (l2.a - l1.a)) != 0) {
//             return {0, Vector(), Vector()};
//         } else {
//             auto maxx1 = max(l1.a.x, l1.b.x);
//             auto minx1 = min(l1.a.x, l1.b.x);
//             auto maxy1 = max(l1.a.y, l1.b.y);
//             auto miny1 = min(l1.a.y, l1.b.y);
//             auto maxx2 = max(l2.a.x, l2.b.x);
//             auto minx2 = min(l2.a.x, l2.b.x);
//             auto maxy2 = max(l2.a.y, l2.b.y);
//             auto miny2 = min(l2.a.y, l2.b.y);
//             Vector p1(max(minx1, minx2), max(miny1, miny2));
//             Vector p2(min(maxx1, maxx2), min(maxy1, maxy2));
//             if (!pointOnSegment(p1, l1)) {
//                 swap(p1.y, p2.y);
//             }
//             if (p1 == p2) {
//                 return {3, p1, p2};
//             } else {
//                 return {2, p1, p2};
//             }
//         }
//     }
//     auto cp1 = ((l2.a - l1.a) ^ (l2.b - l1.a));
//     auto cp2 = ((l2.a - l1.b) ^ (l2.b - l1.b));
//     auto cp3 = ((l1.a - l2.a) ^ (l1.b - l2.a));
//     auto cp4 = ((l1.a - l2.b) ^ (l1.b - l2.b));

//     if ((cp1 > 0 && cp2 > 0) || (cp1 < 0 && cp2 < 0) || (cp3 > 0 && cp4 > 0) ||
//         (cp3 < 0 && cp4 < 0)) {
//         return {0, Vector(), Vector()};
//     }

//     Vector p = lineIntersection(l1, l2);
//     if (cp1 != 0 && cp2 != 0 && cp3 != 0 && cp4 != 0) {
//         return {1, p, p};
//     } else {
//         return {3, p, p};
//     }
// }

// bool pointInPolygon(Vector a, vector<Vector> p) {
//     int n = p.size();
//     for (int i = 0; i < n; i++) {
//         if (pointOnSegment(a, Line(p[i], p[(i + 1) % n]))) {
//             return true;
//         }
//     }
//     int t = 0;
//     for (int i = 0; i < n; i++) {
//         auto u = p[i];
//         auto v = p[(i + 1) % n];
//         if (u.x < a.x && v.x >= a.x && pointOnLineLeft(a, Line(v, u))) {
//             t ^= 1;
//         }
//         if (u.x >= a.x && v.x < a.x && pointOnLineLeft(a, Line(u, v))) {
//             t ^= 1;
//         }
//     }
//     return t == 1;
// }

// bool segmentInPolygon(Line l, vector<Vector> p) {
//     int n = p.size();
//     if (!pointInPolygon(l.a, p)) {
//         return false;
//     }
//     if (!pointInPolygon(l.b, p)) {
//         return false;
//     }
//     for (int i = 0; i < n; i++) {
//         auto u = p[i];
//         auto v = p[(i + 1) % n];
//         auto w = p[(i + 2) % n];
//         auto [t, p1, p2] = segmentIntersection(l, Line(u, v));

//         if (t == 1) {
//             return false;
//         }
//         if (t == 0) {
//             continue;
//         }
//         if (t == 2) {
//             if (pointOnSegment(v, l) && v != l.a && v != l.b) {
//                 if (((v - u) ^ (w - v)) > 0) {
//                     return false;
//                 }
//             }
//         } else {
//             if (p1 != u && p1 != v) {
//                 if (pointOnLineLeft(l.a, Line(v, u)) || pointOnLineLeft(l.b, Line(v, u))) {
//                     return false;
//                 }
//             } else if (p1 == v) {
//                 if (l.a == v) {
//                     if (pointOnLineLeft(u, l)) {
//                         if (pointOnLineLeft(w, l) && pointOnLineLeft(w, Line(u, v))) {
//                             return false;
//                         }
//                     } else {
//                         if (pointOnLineLeft(w, l) || pointOnLineLeft(w, Line(u, v))) {
//                             return false;
//                         }
//                     }
//                 } else if (l.b == v) {
//                     if (pointOnLineLeft(u, Line(l.b, l.a))) {
//                         if (pointOnLineLeft(w, Line(l.b, l.a)) && pointOnLineLeft(w, Line(u, v)))
//                         {
//                             return false;
//                         }
//                     } else {
//                         if (pointOnLineLeft(w, Line(l.b, l.a)) || pointOnLineLeft(w, Line(u, v)))
//                         {
//                             return false;
//                         }
//                     }
//                 } else {
//                     if (pointOnLineLeft(u, l)) {
//                         if (pointOnLineLeft(w, Line(l.b, l.a)) || pointOnLineLeft(w, Line(u, v)))
//                         {
//                             return false;
//                         }
//                     } else {
//                         if (pointOnLineLeft(w, l) || pointOnLineLeft(w, Line(u, v))) {
//                             return false;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return true;
// }

// vector<Vector> hp(vector<Line> lines) {
//     sort(lines.begin(), lines.end(), [&](const Line &l1, const Line &l2) {
//         Vector d1 = l1.b - l1.a;
//         Vector d2 = l2.b - l2.a;

//         if (d1.toward() != d2.toward()) {
//             return d1.toward() == 1;
//         }

//         return (d1 ^ d2) > 0;
//     });

//     deque<Line> ls;
//     deque<Vector> ps;
//     for (auto l : lines) {
//         if (ls.empty()) {
//             ls.push_back(l);
//             continue;
//         }

//         while (!ps.empty() && !pointOnLineLeft(ps.back(), l)) {
//             ps.pop_back();
//             ls.pop_back();
//         }

//         while (!ps.empty() && !pointOnLineLeft(ps[0], l)) {
//             ps.pop_front();
//             ls.pop_front();
//         }

//         if (((l.b - l.a) ^ (ls.back().b - ls.back().a)) == 0) {
//             if (((l.b - l.a) * (ls.back().b - ls.back().a)) > 0) {

//                 if (!pointOnLineLeft(ls.back().a, l)) {
//                     assert(ls.size() == 1);
//                     ls[0] = l;
//                 }
//                 continue;
//             }
//             return {};
//         }

//         ps.push_back(lineIntersection(ls.back(), l));
//         ls.push_back(l);
//     }

//     while (!ps.empty() && !pointOnLineLeft(ps.back(), ls[0])) {
//         ps.pop_back();
//         ls.pop_back();
//     }
//     if (ls.size() <= 2) {
//         return {};
//     }
//     ps.push_back(lineIntersection(ls[0], ls.back()));

//     return vector(ps.begin(), ps.end());
// }
}; // namespace Geometry