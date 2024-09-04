#include <iostream>

using namespace std;

class A
{
public:
    int a_x;
};
class B
{
public:
    int b_x;
};

class C:public A, public B
{
public:
//    int a_x;
//    int b_x;
    int c_x;
};

int main() {
    cout << sizeof(C) << endl;

    C c;
    c.a_x = 100; //继承自基类A
    c.b_x = 200; //继承自基类B
    c.c_x = 300;

    return 0;
}
