#include <iostream>
#include <Cstring>

using  namespace std;

//定义一个类
class CAnimal
{
//访问控制符
public:
    //属性 成员变量
    char name[32];
    int age;

    //方法 成员函数
    void jiao(const char *voice)
    {
        //在成员函数中可以直接访问成员变量
        cout << name << ":" << voice << endl;
    }
};

class Teacher
{
public:
    char name[32];

    void set_age(int age) //设置_age 属性
    {
        if ((age > 200) || (age < 0)) //阈值判断  函数的形参的合法性检查
        {
            cout << "age error"  << endl;
            return ;
        }
        cout << "void set_age(int age) " << endl;
        _age = age;  //在类的内部访问private成员变量
    }

    int get_age()
    {return _age;}

private:
//protected:
    int _age;
    char _sex;
};

class Test
{
public:
    void func()
    {
        f1();
        f2();
        f3();
    }

private:
    void f1()
    {}
    void f2()
    {}
    void f3()
    {}
};

int main() {
    /*
    //实例化普通对象
    CAnimal cat;

    //通过数组实例化多个对象
    CAnimal cats[10];

    //定义指针变量
    CAnimal *p;
    p = &cat;

    cat.age = 1;
    cout << cat.age << endl;

    p->age = 2;
    cout << cat.age << endl;
    cout << p->age << endl;

    memset(cat.name, 0, sizeof(cat.name));
    strcpy(cat.name, "xiaohua");

    cat.jiao("miao miao");

    cout << cat.name << endl;
    */

    Teacher t;
    //t._age = -10000; //error: 'int Teacher::_age' is private within this context
   // t.play();
    //cout << t._age << endl;

    //t.set_age(30);
    t.set_age(-10000);
    cout << t.get_age() << endl;

    return 0;
}
