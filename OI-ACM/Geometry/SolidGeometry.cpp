#include <bits/stdc++.h>
using namespace std;

namespace Gepmetry {
using ld = double;
const ld pi = acos(-1), eps = 1e-8;
int sgn(ld x) { return (x > eps) - (x < -eps); }
int cmp(ld x, ld y) { return sgn(x - y); }
ld norm(ld x) { return sgn(x) ? x : 0; }
ld toRad(ld d) { return d * pi / 180; }
struct Vector {
    ld x, y, z;
    Vector(ld x_ = 0, ld y_ = 0, ld z_ = 0) : x(x_), y(y_), z(z_) {}
    Vector operator-() const { return Vector(-x, -y, -z); }
    friend Vector operator+(Vector a, Vector b) { return Vector(a.x + b.x, a.y + b.y, a.z + b.z); }
    friend Vector operator-(Vector a, Vector b) { return Vector(a.x - b.x, a.y - b.y, a.z - b.z); }
    friend Vector operator*(Vector a, ld b) { return Vector(a.x * b, a.y * b, a.z * b); }
    friend Vector operator*(ld a, Vector b) { return Vector(a * b.x, a * b.y, a * b.z); }
    friend Vector operator/(Vector a, ld b) { return Vector(a.x / b, a.y / b, a.z / b); }
    friend bool operator==(Vector a, Vector b) {
        return !cmp(a.x, b.x) && !cmp(a.y, b.y) && !cmp(a.z, b.z);
    }
    friend ld operator*(Vector a, Vector b) { return a.x * b.x + a.y * b.y + a.z * b.z; } // 点乘
    friend Vector operator^(Vector a, Vector b) {
        return Vector(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
    } // 叉乘
    Vector unit() { return (*this) / len(); }    // 单位向量
    ld len() { return sqrt((*this) * (*this)); } // 欧几里得距离
    ld len2() { return (*this) * (*this); }      // 欧几里得距离平方
    ld lenM() { return abs(x) + abs(y); }        // 曼哈顿距离
    Vector rotate() { return Vector(-y, x); }    // 逆时针旋转90
    Vector rotate(Vector u, double rad) {        // 逆时针旋转rad
        u = u.unit();
        double c = cos(rad), s = sin(rad);
        double m00 = c + u.x * u.x * (1 - c);
        double m01 = u.x * u.y * (1 - c) - u.z * s;
        double m02 = u.x * u.z * (1 - c) + u.y * s;
        double m10 = u.y * u.x * (1 - c) + u.z * s;
        double m11 = c + u.y * u.y * (1 - c);
        double m12 = u.y * u.z * (1 - c) - u.x * s;
        double m20 = u.z * u.x * (1 - c) - u.y * s;
        double m21 = u.z * u.y * (1 - c) + u.x * s;
        double m22 = c + u.z * u.z * (1 - c);
        return Vector(m00 * x + m01 * y + m02 * z, m10 * x + m11 * y + m12 * z,
                      m20 * x + m21 * y + m22 * z);
    }
    friend istream &operator>>(istream &is, Vector &p) { return is >> p.x >> p.y >> p.z; }
    friend ostream &operator<<(ostream &os, Vector &p) {
        return os << "(" << norm(p.x) << ", " << norm(p.y) << ", " << norm(p.z) << ")";
    }
};

} // namespace Gepmetry
using namespace Gepmetry;
int main() {
    Vector r(1, 1, 1);
    Vector u(0, 0, 1);
    Vector res;
    for (int i = 0; i < 360; i += 45) {
        res = r.rotate(u, toRad(i));
        cout << i << ' ' <<  res << '\n';
    }
}