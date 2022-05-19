#include <bits/stdc++.h>
#include "Point.h"
using namespace std;
inline void Point::clacPoint()
{
    distance = x_ + y_;
} //内联函数

void Point::printPoint()
{
    clacPoint();
    std::cout << "distance = " << distance << endl;
} //成员函数

Point::Point(int x, int y) : x_(x), y_(y) {}   //构造函数

// Point::Point(int x, int y) { x_ = x, y_ = y; } //构造函数

Point::Point() { x_ = 0, y_ = 0; }             //默认构造函数

// Point::Point(int x = 0, int y = 0) { x_ = x, y_ = y; }

Point::~Point() { cout << x_ << " " << y_ << endl; } //析构函数

Point Point::operator+(const Point &t) const
{
    Point sum(0, 0);
    sum.x_ = x_ + t.x_;
    sum.y_ = y_ + t.y_;
    return sum;
} //重载运算符
int main()
{
    Point M(10, 20); //隐式调用
    M.printPoint();

    Point N = Point(10, 20); //显式调用
    N = Point(20, 30);       //再次赋值
    N.printPoint();

    Point S;
    S = M + N;
    S.printPoint();
    return 0;
}
