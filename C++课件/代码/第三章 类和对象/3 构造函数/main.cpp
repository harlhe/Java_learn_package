#include <iostream>

using  namespace std;

class C
{
public:
    int x;

    C(int a)
    {
        x = a;
    }
};

class Box
{
public:
    //无参构造函数 默认构造函数

    Box():p(_len),sum(100),n(100) //n(100)在构造n对象的时候传参，会调用C(int)有参的构造函数，从而绕过了调用C(){}无参构造函数
    {
        cout << "Box()" << endl;
        //对成员变量进行初始化: 设置一些默认值
        _len = 10;
        _w = 10;
        _h = 10;
//        p = _len; //不是定义引用了，对引用的对象进行赋值 还是没有初始化！！
    //    sum = 1000; //也不叫初始化，叫赋值
    }

    //有参构造函数
    Box(int len, int w, int h):_len(len), _w(w), _h(h),p(_len),sum(100),n(100)
    {
        cout << "Box(int len, int w, int h)" << endl;
     //   _len = len;
     //   _w = w;
      //  _h = h;
    }

    Box(int len, int w):p(_len),sum(100),n(100)
    {
        cout << "Box(int len, int w)" << endl;
        _len = len;
        _w = w;
        _h = 10;
    }

    int get_len(){return _len;}
    int get_w() {return _w;}
    int get_h() {return _h;}

private:
    int _len;
    int _w;
    int _h;

    int& p;
    const int sum;
    C n;
};

int main() {
    Box a, b; //自动调用无参（默认）构造函数  a.Box();

   // Box x[4];
/*
    Box c(); //不是实例化一个对象，而是声明一个函数 返回值是Box，函数的名字叫做c，函数的形参列表为空

    cout << a.get_len() << endl;
    cout << a.get_w() << endl;
    cout << a.get_h() << endl;

    Box b1(20, 10, 10); //自动触发Box(int len, int w, int h)有参构造函数的调用
    Box b2(20, 10); //自动触发Box(int len, int w)有参构造函数的调用

    Box b3(100, 20, 10);
    cout << b3.get_len() << endl;
    cout << b3.get_w() << endl;
    cout << b3.get_h() << endl;
*/

    return 0;
}
