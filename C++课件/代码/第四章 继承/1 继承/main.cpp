#include <iostream>
#include <string>

using namespace std;

//定义一个Person基类
class Person
{
public:
    void print()
    {
        cout << "name: " << _name << endl;
        cout << "age: " << _age << endl;
    }
protected:
    string _name; //名字
    int _age; //年龄
};

//Student 派生类
class Student : public Person
{
public:
    void set_age(int age)
    {
        _age = age;
    }

    int get_age()
    {
        return _age;
    }

    void set_name(string name)
    {
        _name = name;
    }

    string get_name()
    {
        return _name;
    }
protected:
//    string _name; //名字
//    int _age; //年龄
   // string _stuId;
};

//Teacher 派生类
class Teacher : public Person
{
protected:
   // string _jobId;
};

//基类
class A
{
public:
    int x;
protected:  //protected修饰的成员 在派生类中可以访问到
    int y;
private:  //private修饰的成员 在派生类中不能够访问到
    int z;
};

//派生类
class B : public A {
public:
    void func()
    {
        x = 100;
        y = 100;
        //基类中的private成员在派生类中、外不能访问到
        //z = 100;
    }
};

class C : private A
{
public:
    void func()
    {
        x = 100;
        y = 100;
        //基类中的private成员在派生类中、外不能访问到
        //z = 100;
    }
    /*
private:
    int x;
private:
    int y;
private:
    int z;
     */
};

class D : protected A
{
protected:
    int x;
protected:
    int y;
private:
    int z;

public:
    void func()
    {
        x = 100;
        y = 100;
        //基类中的private成员在派生类中、外不能访问到
       // z = 100;
    }
    /*
protected:
    int x;
protected:
    int y;
private:
    int z;
     */
};

//class E: public C
class E: public D
{
public:
    void func()
    {
        x = 100;
        y = 100;
        //基类中的private成员在派生类中、外不能访问到
        //z = 100;
    }
};
int main()
{
    Student s;
    Teacher t;

    s.set_age(10);
    cout << s.get_age() << endl;

    s.set_name("lisi");
    cout << s.get_name() << endl;

    s.print();

    cout << sizeof(Person) << endl;
    cout << sizeof(Student) << endl;
    cout << sizeof(Teacher)  << endl;

    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;

    B b;
    b.x = 100;
  //  b.y = 100;
  //  b.z = 100;

    C c;
 //   c.x = 100;
//    c.y = 100;
 //   c.z = 100;
    return 0;
}
