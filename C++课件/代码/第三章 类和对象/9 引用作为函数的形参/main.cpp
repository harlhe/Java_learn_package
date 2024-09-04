#include <iostream>
#include <Cstdlib>
#include <Cstring>
#include <Cwchar>

using namespace std;

class Test {
public:
    int *sum;
    int x;
    int y;

    Test() {
        cout << "Test()" << endl;
        x = 0;
        y = 0;
        sum = new int[4];
    }

    Test(int a, int b) : x(a), y(b)
    {
        cout << "Test(int a, int b) : x(a), y(b)" << endl;
        sum = new int[4];
    }

    //拷贝构造函数
    Test(const Test &t) //t 引用的是 右值
    {
        cout << "Test(const Test &t)"  << endl;
        x = t.x;
        y = t.y;
        sum = new int[4];
        //将t.sum 所指向的空间中的内容拷贝到sum所指向的空间中
        for (int i = 0; i < 4; i++)
            sum[i] = t.sum[i];
    }
    ~Test()
    {cout << "~Test()" << endl;delete[] sum;
    }
};

//void func(Test t) // Test t = t1; 触发拷贝构造函数的调用，而且func函数结束，t对象还需要销毁
void func(const Test &t) //void func(const Test *t)
{
    //t.x = 100; //t->x = 100;
}

int main() {
    Test t1(10, 20); //调用构造函数： Test(int a, int b) : x(a), y(b)

    func(t1);

    return 0;
}
