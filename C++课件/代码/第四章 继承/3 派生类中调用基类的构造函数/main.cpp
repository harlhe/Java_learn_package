#include <iostream>

using namespace std;

//基类
class A
{
protected:
    int z;
private:
    int x;

public:
    A()
    {cout << "A()" << endl;}
    ~A()
    {cout << "~A()" << endl;}

    A(int a, int b):z(a), x(b)
    {cout << "A(int a, int b):z(a), x(b)" << endl;}

    int get_z() {return z;}
    int get_x() {return x;}
    void set_x(int x)
    {this->x = x;}
};

class B : public A
{
public:
    B()
    {cout << "B()" << endl;}
    ~B()
    {cout << "~B()" << endl;}

    //在派生类中指定调用基类中某个构造函数
    B(int a, int b):A(a, b)
    {
       // z = a;
       // set_x(b);
        cout << "B(int a, int b)" << endl;
    }
};

int main()
{
    //构造一个派生类的对象
  //  B b;
    B t(10, 20);

    cout << t.get_z() << endl;
    cout << t.get_x() << endl;

    return 0;
}
