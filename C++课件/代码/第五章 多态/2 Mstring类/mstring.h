
#ifndef UNTITLED_MSTRING_H
#define UNTITLED_MSTRING_H

#include <iostream>
using namespace std;

typedef unsigned int u32_t;

#define DEFAULTLEN 10

class Mstring{
private:
    //保存字符串的指针
    char *_data;
    //保存字符串的长度
    u32_t _len;
    //保存在堆上申请的空间的长度
    u32_t _maxLen;

public:
    //默认构造函数
    Mstring();
    //带参数的构造函数
    Mstring(const char *);
    //拷贝构造函数
    Mstring(const Mstring &);
    //析构函数
    ~Mstring();

    //=重载
    Mstring &operator=(const Mstring &);

    //扩容
    void extend(u32_t);
    //重载[]
    char operator [](u32_t);
    //重载+
    Mstring operator +(const Mstring &); //t1+t2
    //重载>
    bool operator >(const Mstring &); //t1>t2
    //重载<
    bool operator <(const Mstring &); //t1<t2

    //再原有的对象上追加一个对象
    Mstring &append(const Mstring &); //t = s1.append(s2);
    Mstring &append(const char *); //t = s1.append("hello");

    u32_t length() const;

    //销毁函数
    void destroy();
    //重载 <<
    friend ostream &operator << (ostream &, const Mstring &); //cout << s << endl;
};

#endif //UNTITLED_MSTRING_H
