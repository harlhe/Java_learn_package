#include <iostream>
#include "test.h"

using namespace std;

//声明一个命名空间，空间的名字叫做nameA
namespace nameA
{
    int x;
    void func()
    {cout << "nameA" << endl;}
}

namespace nameB
{
    int x;
    void func()
    {cout << "nameB" << endl;}
}

/*
//命名空间的定义必须是全局的，一下代码是错误！！
void test()
{
    namespace A
    {
        int a;
    }
    namespace B
    {
        int a;
    }
    A::a = 100;
    B::a = 1000;
}
 */

//命名空间的嵌套定义
namespace nameC
{
    int a = 100;
    namespace A
    {
        int a = 200;
    }
}

namespace studentInfoHandle
{
    void func()
    {
        cout << "studentInfoHandle" << endl;
    }
};

int main() {
    //访问空间中的成员变量
    nameA::x = 100;
    nameB::x = 1000;
    cout << nameA::x << endl;
    cout << nameB::x << endl;

    //访问空间中的成员函数
    nameA::func();
    nameB::func();

    cout << nameC::a << endl;
    cout << nameC::A::a << endl;

    MySpace::func1();
    MySpace::func2(100);

    //MySpaceB::func2();
    studentInfoHandle::func();

    //给命名空间studentInfoHandle 取别名
    namespace stuInfoH = studentInfoHandle;
    stuInfoH::func();  //studentInfoHandle::func();

    return 0;
}
