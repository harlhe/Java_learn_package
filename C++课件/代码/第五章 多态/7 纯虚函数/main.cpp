#include <iostream>

using namespace std;

//游戏中所有英雄的基类
//抽象类：规定了某一类事物的特征
class Hero
{
public:
    virtual void huicheng() = 0;//纯虚函数 英雄的回城功能
    virtual void attack() = 0;
};

//假设这是对Libai类进行声明 (libai.h)
class Libai:public Hero
{
public:
    void huicheng(); //对派生类中重写基类中的纯虚函数的声明
    void attack();
};

//对Libai类的实现 （libai.cpp）
void Libai::huicheng() {
     cout << "Libai::huicheng" << endl;
}

void Libai::attack() {

}

class Caocao:public Hero
{
public:
    void huicheng()
    {
        cout << "Caocao::huicheng" << endl;
    }
};

int main()
{
#if 0
    Libai h1;
    Caocao h2;

    h1.huicheng();
    h2.huicheng();

    Hero *p;
    p = &h1;
    p->huicheng();

    p = &h2;
    p->huicheng();

  //Hero h; //抽象类不能实例化对象
#endif
    return 0;
}