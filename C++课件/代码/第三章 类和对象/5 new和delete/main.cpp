#include <iostream>
#include <Cstdlib>
#include <Cstring>

using namespace std;

class Box
{
public:
    int len;
    int w;
    int h;

    Box():len(10),w(10),h(10)
    {cout << "Box()" <<endl;}

    Box(int x, int y, int z):len(x),w(y),h(z)
    {cout << "Box(int x, int y, int z):len(x),w(y),h(z)" << endl;}

    ~Box()
    {cout << "~Box()" << endl;}
};

int main() {
    /*
    //在堆上申请一个int类型大小的空间（4Bytes）,并且将申请的堆空间的内容初始化为10
    int *p = new int(10);
    delete p;
    //在堆上申请4个int类型大小的空间（4*sizeof(int)==16Bytes） 4：数组的长度
    int *p2 = new int[4];
    for (int i = 0; i < 4; i++)
    {
        cout << *(p2 + i) << endl; //cout << p2[i] << endl;
    }
    delete[] p2;
    //在堆上申请一个Box类型大小的空间
    Box *p3 = new Box; //调用无参的构造函数
    delete p3;
    //在堆上申请四个Box类型大小的空间
    Box *p4 = new Box[4]; //调用无参的构造函数
    delete[] p4;
     */
    //在堆上申请一个Box类型大小的空间
    Box *p5 = new Box(10, 10, 10); //调用带参数的构造函数
    delete p5;

    Box *p6 = (Box *)malloc(sizeof(Box)); //不会调用构造函数！！
    free(p6); //不会调用析构函数

    return 0;
}
