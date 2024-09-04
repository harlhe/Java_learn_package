#include <iostream>

using namespace std;

//基类
class A
{
public:
    A()
    {cout << "A()" << endl;}
    ~A()
    {cout << "~A()" << endl;}
};

class B : public A
{
public:
    B()
    {cout << "B()" << endl;}
    ~B()
    {cout << "~B()" << endl;}
};

int main()
{
    //构造一个派生类的对象
    B b;

    return 0;
}
