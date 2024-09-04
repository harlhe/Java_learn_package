#include <iostream>
#include <Cstring>
using namespace std;

//const 修饰成员变量
class A
{
public:
    const int x; //成员常量 只能在初始化成员列表中被赋值

    A():x(100)
    {}
    /*  A a;
     *  a.x = 1000; //错！！
     * */
};

//const 修饰成员函数
class B
{
public:
    int x;
    B():x(100){}

    int getX() const
    {
        return x;
    }
};

#if 0
//const 不能修饰全局函数
void func() const //error: non-member function 'void func()' cannot have cv-qualifier
{}
#endif

class C
{
public:
    int x;
    C():x(100)
    {}

    int getX() const
    {return x;}

    void setX(int x)
    {this->x  = x;}
};

//const修饰引用：目的是不希望通过引用改变被应用对象的内容
void func(const B &t)
{
   // t.x++;
}

//const修饰函数的返回值
const int func2()
{
    int x = 100;
    return 100;
}

const B func3()
{
    B b;
    return b;
}

//file10000
const char *func4() //之所以用const修饰 是希望调用函数的用户不能够修改这个函数体内在堆上申请的空间中的内容
{
    char *p = new char[10];
    strcpy(p, "hello");
    return p;
}

const int *func5()
{
    int a[4];
    return a; //返回栈上的地址是没有意义的！因为这块栈空间在函数调用结束后会被系统自动回收，所以我们使用一个指针变量来接收这个函数的返回值是没有意义的q
}

const B &func6(B &t) //返回值是引用时，等价于返回值是：const B *func6()
{
   // B b;
    //return b; //如果返回值是引用，return b 编译器在处理的时return &b,返回的是栈上的一个地址是有问题的！
    return t;
}

int main() {
    //const修饰函数的返回值
    int x = func2();   //a = b  (int = const int) 不能通过a将b的值修改，所以b是不是const的无所谓
    cout << x << endl;

    B b = func3();
    cout << b.x << endl;

    const char *p = func4(); // error: invalid conversion from 'const char*' to 'char*'
    cout << p << endl;
   // *p = 'H';

    int a = 100;
    const int *p2 = &a;
    const int *p3 = p2;
//    *p3 = 1000; //*p2 = 1000   a = 1000

    B t = func6(b); //t = b 不可能通过t修改b
    const B &t2 = func6(b); // B &t2 = b;  能够通过应用t2修改b
#if 0
    //const修饰普通变量
    const int a = 10; //变量a是只读的
    //a = 100; //error: assignment of read-only variable 'a'

    int x = 100;
    const int *p = &x; //*p是只读的，指针p不能够改变他所指向的内存空间的内容
   // *p = 10;

    int const *p2 = &x; //等效于 const int *p2 = &x;

    const  int *const p3 = &x; //p3是只读的：p3这个指针一旦初始化后就不能够再指向别的内存空间了   *p3是只读的
    //p3 = &a; //error: assignment of read-only variable 'p3'
    //*p3 = 1000; //error: assignment of read-only location '*(const int*)p3'

    int const *const p4 = &x; //等价于  const  int *const p3 = &x;

    const C c;
    //c.x = 1000; // error: assignment of member 'C::x' in read-only object
    //c.setX(); //error: passing 'const C' as 'this' argument discards qualifiers [-fpermissive]
    cout << c.x << endl;
#endif
    return 0;
}