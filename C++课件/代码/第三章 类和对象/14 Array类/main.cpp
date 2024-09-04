#include <iostream>
#include <string>

#include "array.h"

using namespace std;

/*需求：
 * 1、设计一个动态数组类，存储整型数据
 * 2、实现如下功能：
 *      A、实现自动扩容（当数组长度不够时能够自动对数组进行扩容）
 *      B、销毁动态数组
 *      C、在指定位置插入元素
 *      D、删除指定位置的元素
 *      E、删除指定的元素
 * */


int main()
{
    /*
    Array a; //调用默认构造函数
    Array b(10); //调用带参数的构造函数，构造一个动态数组，数组中的元素的个数是10个
    Array c = b; //调用拷贝构造函数

    cout << "befor ........" << endl;
    for (int i = 0; i < c.length(); i++)
        cout << c.getData(i) << " : " << b.getData(i) << endl;

    c.extend(); //扩容
    cout << "after ........." << endl;
    for (int i = 0; i < c.length(); i++)
        cout << c.getData(i) << endl;
    c.destroy();
    */
    Array a; //调用默认构造函数
    a.insert(0, 10);
    a.insert(1, 20);
    a.insert(2, 30);
    a.insert(3, 40);

    for (int i = 0; i < a.length(); i++)
        cout << a.getData(i) << endl;

    return 0;
}
