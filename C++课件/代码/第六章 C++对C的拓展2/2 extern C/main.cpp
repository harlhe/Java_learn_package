#include <iostream>

#include "example.h"

#if 0
extern "C"
{
    #include "example.h"
 //   extern int add( int x, int y );
 //   extern int add2( int x, int y );
}
#endif

using namespace std;

int main()
{
    add(2, 3);
    return 0;
}