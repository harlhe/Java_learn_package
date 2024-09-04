#include <iostream>

using namespace  std;

/*
 * 重载：overload 重载只发生在同一个作用域中，比如一个类中的多个成员函数函数名相同，但是形参数据类型或或者个数或者顺序不相同，那么我们就称这些函数是重载
 * 重写：override 也叫做覆盖 重写发生在不同的作用域中（发生在基类和派生类中），而且派生类中的成员函数的名字和基类中的虚函数的名字相同，并且返回值相同，形参列表也相同！！！
 * 隐藏：隐藏发生在不同的作用域中（发生在基类和派生类中），派生类中的成员函数的名字、返回值、形参列表与基类中的普通函数完全相同， 派生类中的成员函数的名字和基类中的成员函数的名字
 * 相同，但是形参列表不同或者返回值不同这也叫做隐藏，此时基类中的那个函数不论是普通函数还是虚函数都会被派生类中的函数隐藏
 * */

class Hero
{
public:
    virtual void huicheng()
    {cout << "Base::huicheng" << endl;}

    void func2()
    {cout << "Base::func2" << endl;}
};

class Libai : public Hero
{
public:
    void func2() //隐藏了基类中的func2函数
    {cout << "A::func2" << endl;}

    void func2(int x) //隐藏
    {}

    void huicheng() //对基类中虚函数的重写（override）
    {cout << "Libai::huicheng" << endl;}

    void huicheng(int x){} //隐藏
};

class Caocao : public Hero
{
public:
    void func2() //隐藏了基类中的func2函数
    {cout << "A::func2" << endl;}

    void huicheng() //对基类中虚函数的重写（override）
    {cout << "Caocao::huicheng" << endl;}
};

class Houyi : public Hero
{};

void goback(Hero &h)
{
    h.huicheng(); //调用h所引用的派生类对象中重写的huicheng函数，因为huicheng函数在基类中是虚函数
    h.func2(); //调用基类中的func2函数  因为func2函数在基类中不是虚函数
}

int main() {
    Libai libai;
    Caocao caocao;
    Houyi houyi;

    //libai回城
    goback(libai);
    goback(caocao);
    goback(houyi);

#if 0
  a.func1();
    a.func2();

    Base *p; // 基类指针
    p = &a; // 基类指针指向派生类对象
    p->func2(); // Base::func2
    p->func1(); // A::func1, 调用的是指针p所指向的派生类中的func1函数
#endif
    return 0;
}
