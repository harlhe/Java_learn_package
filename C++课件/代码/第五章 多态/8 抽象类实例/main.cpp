#include <iostream>

using namespace std;

typedef unsigned int u32_t;

//抽象基类
class Shape
{
public:
    virtual double getPermiter() = 0; //求周长
    virtual double getArea() = 0; //求面积
};

//派生出trangle类
class Trangle : public Shape
{
public:
    Trangle():_a(10),_b(10),_c(10)
    {}

    Trangle(u32_t a, u32_t b, u32_t c):_a(a),_b(b),_c(c)
    {}

    double getPermiter()
    {
        return double(_a + _b + _c);
    }

    double getArea()
    {
        return 1000;
    }

private:
    u32_t _a,_b,_c;
    u32_t _permiter; //周长
    double _area; //面积
};

//#define PI 3.14
//派生出一个 Circle
class Cirle : public Shape
{
private:
    double _r; //半径
    double _permiter; //周长
    double _area; //面积
    static double pi; //声明一个静态的成员变量

public:
    Cirle():_r(10)
    {}
    double getPermiter();
    double getArea();
};

//定义一个静态的成员变量
double Cirle::pi = 3.14;
double Cirle::getPermiter() {
    return 2*pi*_r;
}

double Cirle::getArea() {
    return pi*_r*_r;
}

int main()
{
    Trangle x;
    cout << x.getPermiter() << endl;

    Cirle x2;
    cout << x2.getPermiter() << endl;
    cout << x2.getArea() << endl;

    //用一个数组来保存一个三角形和一个圆
    Shape *shapes[2];
    shapes[0] = &x;
    shapes[1] = &x2;

    for (int i = 0; i < 2; i++)
    {
        cout << shapes[i]->getArea() << endl;
        cout << shapes[i]->getPermiter() << endl;
    }

    return 0;
}