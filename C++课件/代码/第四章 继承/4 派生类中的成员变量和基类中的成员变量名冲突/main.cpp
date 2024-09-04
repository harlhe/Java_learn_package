#include <iostream>

using namespace std;

//基类
class A
{
public:
    A():a_x(10), a_y(10)
    {}

    int a_x;
    int a_y;
};

//派生类
class B : public A {
public:
    B() : b_x(20), a_x(20)  //a_x B类中的
    {
        A::a_x = 30; //在派生类内部访问基类中同名的成员变量
    }

    int b_x;
    int a_x; //和基类中的成员变量名字冲突了
};

int main()
{
    //派生类会不会继承基类中同名的属性呢？可以继承的！！
    cout << sizeof(B) << endl; //16

    B b;
    //b.a_x: 派生类中的成员变量
    cout << b.a_x << endl;

    //通过派生类对象访问基类中的同名成员变量
    cout << b.A::a_x << endl;


    return 0;
}
