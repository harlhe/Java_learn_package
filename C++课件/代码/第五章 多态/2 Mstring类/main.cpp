#include <iostream>
#include "mstring.h"

using namespace std;

/* 自己动手实现一个类似于string类的Mstring类，完成如下功能的设计
 * 1、能够存储字符串
 * 2、能够自动扩容
 * 3、能够使用下标法访问字符串中的元素
 * 4、使用=对两个Mstring对象进行赋值
 * 5、使用+实现字符串的追加
 * 6、使用 > >= < <= == !=对两个Mstring对象进行比较
 * */

int main() {
#if 0
    Mstring s1;
    Mstring s2("hello");
    Mstring s3 = s2;
    cout << s3 << endl;

    s1 = s3;
    cout << s1 << endl;

    cout << s2[4] << endl;
    cout << s2[6] << endl;

    Mstring s4("world");
    Mstring s5 = s2+s4;
    cout << s5 << endl;
#endif
    Mstring s1("hello");
    Mstring s2("hello");

   // s1.append(s2);
  //  s1.append("hahaha"); //const char *
   // cout << s1 << endl;
    if (s2 > s1)
        cout << "s2 > s1" << endl;
    else
        cout << "s2 <= s1" << endl;

    s1.destroy();
    s1.destroy();
    s2.destroy();

    Mstring *p = new Mstring("hello");
    delete p;
    return 0;
}
