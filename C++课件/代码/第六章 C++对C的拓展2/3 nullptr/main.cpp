#include <iostream>

using namespace std;

#if 1
void func(int *p)
{
    cout << "void func(int *p)" << endl;
}
#endif

void func(int p)
{
    cout << "void func(int p)" << endl;
}

int main() {
    int *p = NULL;//  C语言中：NULL ==  (void *)0   C++中： 0

    //func(NULL); //func(0)
    func(nullptr); //func((void *)0)
   // int *p2 = NULL;
    int *p2 = nullptr;

    func(p2);

    return 0;
}
