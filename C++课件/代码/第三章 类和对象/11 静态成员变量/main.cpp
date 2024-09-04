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

    static int cnt; //只是声明了一个静态成员变量，不是类或者对象的成员变量，但是他的作用域是在类和这类的所有的实例化对象
};

//定义了Sheep这个类中的静态成员变量cnt，并且初始化为0（如果不初始化默认为0）
int Sheep::cnt = 0;

int main() {
    //构造了10个Sheep对象: 购买了10头羊
    Sheep *p = new Sheep[10];
    cout << Sheep::cnt << endl;

    Sheep s1;
    cout << s1.cnt << endl;

    Sheep s2;

    cout << sizeof(s2) << endl;
    cout << Sheep::cnt << endl;
    cout << s1.cnt << endl;
    cout << s2.cnt << endl;

    return 0;
}
