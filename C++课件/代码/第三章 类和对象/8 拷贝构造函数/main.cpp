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
int main() {
    Test t1(10, 20); //调用构造函数： Test(int a, int b) : x(a), y(b)
    t1.sum[0] = 100;t1.sum[1] = 101;t1.sum[2] = 102;t1.sum[3] = 103;
    //使用已经构造好的对象t1  初始化一个新的对象
    Test t2 = t1; //调用拷贝构造函数  t2.Test(t1);
    cout << t2.sum << endl;
    cout << t1.sum << endl;
    for (int i = 0; i < 4; i++)
        cout << t2.sum[i] << endl;

    return 0;
}
