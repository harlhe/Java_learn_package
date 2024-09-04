#include <iostream>

using namespace std;

//声明class B
class B;

class A
{
public:
    int y; //客厅

private:
    int x; //卧室

    //将普通函数func  声明为该类的友元函数
    friend void func(A &t, B &t2);
};

class B
{
public:
    int y; //客厅

private:
    int x; //卧室

    //将普通函数func  声明为该类的友元函数
    friend void func(A &t, B &t2);
};

void func(A &t, B &t2)
{
    t.y = 100;
    t.x = 100;

    t2.x = 100;
}

class Test
{
public:
    int x;

    //friend ostream &operator << (ostream &os, const Test &t);
    ostream &operator << (ostream &os)
    {
        os << x;
        return os;
    }
#if 0
    bool operator > (const Test &t)  //t2 > t
    {
        return this->x > t.x;
    }
#endif

    friend bool operator > (const Test &t1, const Test &t2);

};

bool operator > (const Test &t1, const Test &t2)
{
    return t1.x > t2.x;
}
#if 0
ostream &operator << (ostream &os, const Test &t)
{
    os << t.x;
    return os;
}
#endif

int main()
{
    A a;
    B b;
    func(a, b);

    Test t;
 //   cout << t << endl;
    t.x = 100;
    t << cout << endl;

    Test t2;
    t2.x = 1000;

    if (t2 > t)
        cout << "hello"  << endl;
    return 0;
}