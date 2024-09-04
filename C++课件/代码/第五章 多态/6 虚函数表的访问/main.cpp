#include <iostream>
#include <Cstdio>

using namespace std;

typedef void (*Fun)();

class Base
{
public:
    virtual void f() {cout << "f" << endl;}
    virtual void g() {cout << "g" << endl;}
    virtual void h() {cout << "h" << endl;}
};

typedef long long u64_t;
int main()
{
    Base b;
    //虚表指针是对象中的第一个元素，虚表指针的地址就是对象的地址
    printf("%p\n", (u64_t *)(&b)); //&b: Base *

    //既然(int*)(&b) == &_vfptr是虚函数表指针的地址， *(int*)(&b) == *(&_vfptr) == _vfptr == 虚表指针的值，虚表指针的值不就是这个虚表指针所指向的那个
    //虚函数表的首地址
    printf("%p\n", (u64_t *)(*(u64_t *)(&b))); //虚函数表的首地址，虚函数指针的值，_vfptr
    //(u64_t *)(*(u64_t *)(&b)) + 0: 虚函数表中第0个元素的地址
    //(u64_t *)(*(u64_t *)(&b)) + 1: 虚函数表中第1个元素的地址
    //(u64_t *)(*(u64_t *)(&b)) + 2: 虚函数表中第2个元素的地址
    printf("%p\n", (u64_t *)(*(u64_t *)(&b)) + 0);
    printf("%p\n", (u64_t *)(*(u64_t *)(&b)) + 1);
    printf("%p\n", (u64_t *)(*(u64_t *)(&b)) + 2);

    //*((u64_t *)(*(u64_t *)(&b)) + 0) : 取虚函数表中第0个元素的值 == 第1个虚函数的地址
    printf("%p\n", *((u64_t *)(*(u64_t *)(&b)) + 0)); //f函数的指针
    printf("%p\n", *((u64_t *)(*(u64_t *)(&b)) + 1)); //g函数的指针
    printf("%p\n", *((u64_t *)(*(u64_t *)(&b)) + 2)); //h函数的指针

    //*((u64_t *)(*(u64_t *)(&b)) + 2) 代表一个函数指针
    Fun p;
    p = (Fun)(*((u64_t *)(*(u64_t *)(&b)) + 2)); //将h函数的地址/指针指向赋值给了函数指针变量p
    p(); //调用h函数

    p = (Fun)(*((u64_t *)(*(u64_t *)(&b)) + 1)); //将g函数的地址/指针指向赋值给了函数指针变量p
    p(); //调用g函数

    p = (Fun)(*((u64_t *)(*(u64_t *)(&b)) + 0)); //将f函数的地址/指针指向赋值给了函数指针变量p
    p(); //调用f函数
    return 0;
}

