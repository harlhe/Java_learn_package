#include <iostream>

using namespace std;

//宏定义实现一个函数
#define Max(a, b) (a)>(b)?(a):(b)

void test01(){
    int a = 10;
    //给变量a取一个别名b
    int& b = a;
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    cout << "------------" << endl;
    //操作b就相当于操作a本身
    b = 100;
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    cout << "------------" << endl;
    //一个变量可以有n个别名
    int& c = a;
    c = 200; //a = 200
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    cout << "c:" << c << endl;
    cout << "------------" << endl;
    //a,b,c的地址都是相同的
    cout << "a:" << &a << endl;
    cout << "b:" << &b << endl;
    cout << "c:" << &c << endl;
}

struct test
{
    int& a; //8
    int& b; //8
};

typedef struct Teacher
{
    char name[32];
    int age;
}Teacher;

void printfT2(Teacher &t)
{
    cout << t.age << endl;
    t.age = 32;
}

void printfT1(Teacher* const t)
{
    cout << t->age << endl;
    t->age = 33;
}

#define ADD(x,y) x+y

//extern int func(int x, int y);

//函数的声明
inline int func(int x, int y)
{
    return x+y;
}

int main() {
    //test01();
    /*
    int a = 100;
    int& b = a; //error: 'b' declared as reference but not initialize

    int c = 200;
    cout << b << endl;
    b = c; //不是让b引用c，而是将c的值赋值给b 等价于 b = 200, 等价于 a= 200
    cout << b << endl;
    cout << a << endl;
    */

    /*
    //引用所占内存空间大小
    float ch = 'a';
    float& p = ch;

    cout << sizeof(struct test) << endl;
    */

    /*
    Teacher teacher;
    teacher.age = 30;

    printfT2(teacher);
    cout << teacher.age << endl;

    printfT1(&teacher);
    cout << teacher.age << endl;
    */

    int ret;
    ret = Max(10, 20); //ret = 10>20?10:20;

    cout << ADD(10, 20)*10 << endl; //cout << 10+20*10 << endl;

    //func("hello", 10);'
    cout << func(10,20)*10 << endl; //cout << (10+20)*10

    return 0;
}
