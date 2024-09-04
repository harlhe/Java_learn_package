#include <iostream>
#include <string>
#include <Cstring>
#include <Cstdio>

using namespace std;

class Test
{
public:
    int data;
    char *ptr;

    //默认构造函数
    Test()
    {
        cout << "Test()"  <<endl;
        data = 0;
        ptr = new char[10];
    }
    //带参数的构造函数
    Test(int data, const char *src)
    {
        this->data = data;
        if (src)
        {
            this->ptr = new char[strlen(src)+1];
            strcpy(this->ptr, src);
        }
        else
            ptr = new char[10];
    }
    //拷贝构造函数。调用时机：使用一个构造好的对象初始化一个新的对象    Test t1 = t2;
    Test(const Test &t)
    {
        cout << "Test(const Test &t)" << endl;
        //实现深拷贝
        this->data = t.data;
        //this->ptr = t.ptr; //浅拷贝
        if (strlen(t.ptr))
        {
            this->ptr = new char[strlen(t.ptr)+1];
            strcpy(this->ptr, t.ptr);
        }
        else
            ptr = new char[10];
    }

    ~Test()
    {
        if (ptr)
            delete[] ptr;
    }

    //该运算符重载函数由 左操作数调用, 右操作数当做实参传递给该函数， 触发：t1 + t3 -> t1.operator +(t3)
    Test operator +(const Test &t)
    {
        cout << "Test operator +(Test &t)" << endl;
        Test val; //保存最后执行的结果
        val.data = this->data + t.data; //this->data : t1.data
        val.ptr = new char[strlen(this->ptr) + strlen(t.ptr) + 1];
        //将分配的堆空间初始化成\0
        memset(val.ptr, 0, strlen(this->ptr) + strlen(t.ptr) + 1);

        strcat(val.ptr, this->ptr);
        strcat(val.ptr, t.ptr);

        return val;
    }

    bool operator > (const Test &t) // t1>t3
    {
        cout << "bool operator > (const Test &t)" << endl;
        if (strcmp(this->ptr, t.ptr) > 0)
      // if (this->data > t.data)
            return true;
        return false;
    }

    char operator [](int index) // index：下标
    {
        cout << "char operator [](int index)" << endl;
        if (index < 0 || index >= strlen(ptr))
            return '\0';

        return ptr[index];
    }

    Test &operator =(const Test &t) //t1 = t2   t3 = t1 = t2;
    {
        cout << "Test &operator =(const Test &t)" << endl;
        //深拷贝
        delete[] this->ptr;
        this->ptr = new char[strlen(t.ptr) + 1];
        strcpy(this->ptr, t.ptr);

        data = t.data;
        return *this;
    }

    //前置++
    Test &operator ++ ()  //++t1      t3 = ++t1;
    {
        cout << "Test &operator ++ ()" << endl;
        ++data;
        return *this;
    }

    //后置++
    Test operator ++ (int)  // t1++     t3 = t1++;
    {
        cout << "Test operator ++ (int)" << endl;
        //临时变量保存++之前的状态
        Test tmp = *this;
        data++;
        return tmp;
    }

    //<< 重载
    friend ostream &operator << (ostream &os, const Test &t)  // cout << t1 : 左操作数不是一个Test对象，将左操作数和右操作数当作实参传递给该函数
    //cout : ostream这个类的一个实例化对象
    {
        os << t.data << endl;
        os << t.ptr << endl;

        return os;
    }
};

int main() {
#if 0
    // + 运算符重载
    Test t1(10, "hello");

    Test t2 = t1;
    cout << t2.data << endl;
    cout << t2.ptr << endl;

    Test t3(10, "world");

    cout << "**************" <<endl;
    Test t4 = t1 + t3; //20, helloworld
    /*
     * 思考：执行 Test t4 = t1 + t3 语句会调用哪些函数？
     * 执行 t1 + t3表达式 会触发 Test operator +(Test &t)函数的调用
     * 因为+运算符重载函数返回一个构造好的对象，最后执行：
     * Test t4 = val; 触发拷贝构造函数的调用
     * */
    cout << t4.data << endl;
    cout << t4.ptr << endl;


    // > 运算符的重载
    Test t1(10, "heLlo");
    Test t2(20, "hello");

    if (t1 > t2)
        cout << "t1 > t2"  << endl;
    else
        cout << "t1 <= t2"  << endl;

    // [] 运算符的重载
    cout << t1[4]  << endl;//t1.ptr[4]

    // = 符号的重载
    t1 = t2;
    cout << t1.ptr << endl;
    printf("%p, %p\n", t1.ptr, t2.ptr);

    ++t1; //++t1.data;
   // t1++;


    //前置++的重载
    Test t1(10, "heLlo");

    Test t2;

    t2 = ++t1;
    cout << t2.data << endl;
    cout << t1.data << endl;

    //后置++的重载
    Test t3;
    t3 = t1++;
    cout << t3.data << endl; //11
    cout << t1.data << endl; //12

    cout << t1.data << endl;
    cout << t1.ptr << endl;

    string s("hello");
    cout << s << endl;
    cout << t1 << endl;
#endif
    Test t1(10, "heLlo");
    cout << t1 ;
    return 0;
}
