#include<iostream>

using namespace std;

class B;

class A
{
public:
    void func1(B &t);
    void func2(B &t);

//    friend class B;
};

class B
{
private:
    int x;

  //  friend void A::func1(B &t) ;
  //  friend void A::func2(B &t) ;
  friend class A; //将类A声明为友元类
  friend void func(B &t);
};

class C :public B{
    //class A 不是 class C的友元类，因为友元关系不能继承
    // void func() 也不是class C的友元函数，因为友元关系不能继承
};

void A::func1(B &t)
{
    cout << t.x << endl;
}

void A::func2(B &t)
{
    cout << t.x << endl;
}

void func(B &t)
{
    cout << t.x << endl;
}
int main()
{
    B b;
    A a;
    a.func1(b);
    a.func2(b);

    return 0;
}
