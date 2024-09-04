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

    ~Test()
    {
        cout << "~Test()" << endl;
        delete[] sum;
    }
};

void func()
{
    Test *t1 = new Test(10, 20); //调用构造函数： Test(int a, int b) : x(a), y(b)
    t1->sum[0] = 100;
    t1->sum[1] = 101;
    t1->sum[2] = 102;
    t1->sum[3] = 103;

    Test t2 = *t1;
    cout << "t2.x: " << t2.x << endl;
    cout << "t2.y: " << t2.y << endl;

    cout << "t1.sum: " << t1->sum << endl;
    cout << "t2.sum: " << t2.sum << endl;

    //手动释放t1指着所申请的堆空间，意味着销毁掉 *t1这个对象，会自动调用析构函数，顺带手动释放成员变量sum所申请的堆空间
    delete t1;

    cout << t2.sum[0] << endl;
    cout << t2.sum[1] << endl;
    cout << t2.sum[2] << endl;
    cout << t2.sum[3] << endl;
}

int main() {
    /*
    Test t1(10, 20); //调用构造函数： Test(int a, int b) : x(a), y(b)
    t1.sum[0] = 100;
    t1.sum[1] = 101;
    t1.sum[2] = 102;
    t1.sum[3] = 103;

    //使用已经构造好的对象t1  初始化一个新的对象
    Test t2 = t1;
    cout << "t2.x: " << t2.x << endl;
    cout << "t2.y: " << t2.y << endl;

    cout << "t1.sum: " << t1.sum << endl;
    cout << "t2.sum: " << t2.sum << endl;
    */

   // func();
    Test t1(10, 20); //调用构造函数： Test(int a, int b) : x(a), y(b)
    t1.sum[0] = 100;
    t1.sum[1] = 101;
    t1.sum[2] = 102;
    t1.sum[3] = 103;

    Test t2;
    t2.x = t1.x;
    t2.y = t2.y;
   // for (int i = 0; i < 4; i++)
   //     t2.sum[i] = t1.sum[i];
    memcpy(t2.sum, t1.sum, 4*sizeof(int));

    cout << t1.sum << endl;
    cout << t2.sum << endl;

    for (int i = 0; i < 4; i++)
        cout << t2.sum[i] << endl;

    cout << "hello world" << endl;

    Test t3;

    return 0;
}
