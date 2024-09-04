#include <iostream>

using namespace std;

int cnt = 0;

class Sheep {
public:
    char name[32];
    int age;

    Sheep()
    {
        cout << "Sheep()" << endl;
        cnt++;
    }

    ~Sheep()
    {
        cnt--;
    }

    //静态的成员函数
    static int sheep_num() //没有this指针
    {
       // cout << age << endl; //静态成员函数中不能访问非静态的成员变量！！！
        return cnt; //访问静态成员变量
    }

//public:
private:
    static int cnt; //只是声明了一个静态成员变量，不是类或者对象的成员变量，但是他的作用域是在类和这类的所有的实例化对象
};

//定义了Sheep这个类中的静态成员变量cnt，并且初始化为0（如果不初始化默认为0）
int Sheep::cnt = 0;

class Math
{
public:
    static void sin(){}
    static void cos(){}
    static void tan(){}
    static void cotan(){}
};

class searchAlgrithm
{
    //二分查找
};

class sortAlgrithm
{
    //冒泡
    //快排法
    //堆排序
};

int main() {
    //构造了10个Sheep对象: 购买了10头羊
    Sheep *p = new Sheep[10];
 //   cout << Sheep::cnt << endl;

    Sheep s1;
//    cout << s1.cnt << endl;

    Sheep s2;

    cout << sizeof(s2) << endl;
//    cout << Sheep::cnt << endl;
//    cout << s1.cnt << endl;
 //   cout << s2.cnt << endl;

    cout << Sheep::sheep_num() << endl; //建议用类访问静态成员变量和成员函数因为这种访问方式可读性强
    cout << s1.sheep_num() << endl; //不会：sheep_num(&s1);

    Math::sin();

    return 0;
}
