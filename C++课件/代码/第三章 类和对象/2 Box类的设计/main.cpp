#include <iostream>
#include "Box.h"

using namespace std;

int main() {
    Box b;
    b.set_len(10);
    b.set_w(10);
    b.set_h(10);

    cout << b.get_s() << endl;
    cout << b.get_v() << endl;

    return 0;
}
