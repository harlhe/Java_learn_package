#include <iostream>

using namespace std;

class A
{
public:
    void func()
    {cout << "A::func" << endl;}
};

class B :public A
{
public:
   // void func()
   // {cout << "A::func" << endl;}

    //和基类中的成员函数名字相同，参数也相同  隐藏
   // void func()
   // {cout << "B::func" << endl;}

    void func(int x)
    {cout << "B::func(int x)" <<endl;}
};

int main() {
    B b;
    b.func(); //B::func
  //  b.A::func(); //A::func
    b.func(10);

    return 0;
}
