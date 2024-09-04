#include <iostream>

using namespace std;

class C1
{
public:
    int i;  //4
    int j; //4
    int k;  //4
protected:
private:
};

class C2
{
public:
    int i;
    int j;
    int k;
public:
    //int getK(C2 * const this) { return this->k; } //this指针指向调用该成员函数的对象
    int getK() { return k; }
    void setK(int val) { k = val; }
};

class ABC
{
public:
    int x, y, z;
    char name[32];
   // ABC(ABC *const this, int x, int y, int z)
    ABC(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

int main()
{
  //  C1 c1;
    C2 c2, c3;
  //  cout << sizeof(c1) << endl;
 //   cout << sizeof(c2) << endl;
    c2.k = 100;
    c2.getK(); //
    c3.getK();
    c2.setK(100);

    ABC a(1,2,3); //ABC(&a, 1, 2, 3);
    ABC b(1,2,3); //ABC(&b, 1, 2, 3);
    return 0;
}
