#include <iostream>
#include <Cstdio>
#include <Cstdlib>
#include <Cstring>

using namespace std;

class Animal
{
public:
    //char name[32];
    char *name;
    int age;

    //默认构造函数
    Animal()
    {
        cout << "Animal()" << endl;
        //在堆上为指针name分配空间
        name = (char*)malloc(32);
       // name = new char[32];
    }

    Animal(const char *name1) //xiaohua
    {
        int len;
        len = strlen(name1);
        name = (char*)malloc(len + 1);
        strcpy(name, name1);
    }

    //析构函数
    ~Animal()
    {
        cout << "~Animal()" << endl;
        if (name != NULL)
            free(name);
            //delete[] name;
    }
};

int main() {
    Animal a;

    return 0;
}
