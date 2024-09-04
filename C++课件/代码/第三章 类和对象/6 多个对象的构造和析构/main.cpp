#include <iostream>
using namespace std;
class ABC
{
public:
    ABC(int a, int b, int c)
    {
        cout << "ABC(int a, int b, int c)" <<endl;
    }
    ~ABC()
    {
        cout << " ~ABC() " << endl;
    }
private:
    int a;
    int b;
    int c;
};

class MyD
{
public:
    MyD():abc1(1,2,3),abc2(4,5,6)
    {
        cout<<"MyD()"<<endl;
    }
    ~MyD()
    {
        cout<<"~MyD()"<<endl;
    }
private:
    ABC abc1; //c++编译器不知道如何构造abc1
    ABC abc2;

};
int main()
{
    MyD myD;

    return 0;
}
