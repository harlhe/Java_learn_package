#include <iostream>

using namespace std;

#define PI 3.1415

int test(int a = 10, int b = 20)
{
    return a+b;
}

//float func(float r = 10.0, float pi = 3.14)
float func(float r = 10, float pi = 3.14)
{
    //return PI*r*r;
    return pi*r*r;
}

float func2(int r, float pi = 3.14)
{
    cout << r << endl;
    cout << pi << endl;
    return pi*r*r;
}

//声明一个带默认参数的函数
float func4(int r, float pi = 3.14);

//如果带默认参数的函数被声明了，实现的时候不需要默认参数
float func4(int r, float pi)
{
    return pi*r*r;
}

/*
float func3(float pi = 3.14, int r) //错误的
{
    cout << r << endl;
    cout << pi << endl;
    return pi*r*r;
}
 */
int main() {
    int ret;
/*
    ret = test();
    cout << ret << endl;

    ret = test(30);
    cout << ret << endl;

    ret = test(100, 200);
    cout << ret << endl;
*/
    //func();
   // func(20);
  //  func(30, 3.1415);

    func2(10);
    func2(10, 3.1415);
    return 0;
}
