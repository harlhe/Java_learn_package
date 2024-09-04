#include <iostream>

using namespace std;

//间接基类
class A
{
public:
    int a_x;
};
//直接基类
class B : public A
{
public:
    //int a_x;
    int b_x;
};
//直接基类
class C:public A
{
public:
    //int a_x;
    int c_x;
};

//派生类
class D:public B, public C
{
public:
    //继承自B类的
    //int a_x;
    //int b_x;

    //继承自C类的
    //int a_x;
    //int c_x;

    int d_x;
};
int main() {
    cout << sizeof(D) << endl;
    D d;
    d.a_x = 100;

    return 0;
}
