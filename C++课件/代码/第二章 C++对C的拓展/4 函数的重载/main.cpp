#include <iostream>

using namespace  std;
namespace efg
{
    void func()
    {}

    void func(int x)
    {}
}

namespace abc
{
    void func()
    {cout << "void func()" << endl;}
    void func(int x)
    {cout << "void func(int x)" << endl;}
    void func(int x, char y)
    {cout << "void func(int x, char y)" << endl;}
    void func(char x, int y)
    {cout << "void func(char x, int y)" << endl;}
    void func(char y)
    {cout << "void func(char y)" << endl;}
}

void sort(int *a)
{}

void sort(char *a)
{}

void sort(Teacher *a)
{}

int a[10];
sort(a);

char b[10];
sort(b);

Teacher c[10];
sort(c);

int main() {
    abc::func();
    abc::func(10);
    abc::func('H');
    abc::func(10,'a');
    abc::func('a', 10);
    return 0;
}
