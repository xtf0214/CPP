class Point
{
private:
    int x_, y_, distance;
    void clacPoint(); //内联函数

public:
    void printPoint();   //成员函数
    Point(int x, int y); //构造函数
    Point();             //默认构造函数
    // Point(int x = 0, int y = 0);         //默认构造函数
    ~Point();                              //析构函数
    Point operator+(const Point &t) const; //重载运算符
};
