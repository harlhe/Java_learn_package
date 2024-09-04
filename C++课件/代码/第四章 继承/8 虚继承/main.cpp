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

//虚基类
class Animal
{
public:
    string name;
    int age;
};
class Buru : virtual public Animal
{};
class Bird : virtual public Animal
{};
class Bianfu : public Buru, public Bird
{};

int main() {
    cout << sizeof(D) << endl;
    D d;
    d.B::a_x = 100;
    d.C::a_x = 100;

    cout << sizeof(Bianfu)  << endl;
    cout << sizeof(Animal)  << endl;

    Bianfu b;
    b.name = "hahah";
    return 0;
}
