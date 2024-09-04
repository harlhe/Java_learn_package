#include <iostream>

using namespace std;

class A
{
public:
    A()
    {cout << "A::A()" << endl;}
    virtual ~A()
    {cout << "A::~A()" << endl;}
};

class B : public A
{
public:
    int *p;
    B()
    {
        p = new int[4];
        cout << "B::B()" << endl;}
    ~B()
    {
        delete[] p;
        cout << "B::~B()" << endl;}
};
int main()
{
    //A a;
    //B b;
    A *p = new B(); //构造一个派生类对象
    delete p; //通过基类指针，销毁/释放一个派生类对象

    return 0;
}