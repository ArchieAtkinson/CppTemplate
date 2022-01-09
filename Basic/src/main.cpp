#include <iostream>
#include "header.h"

using namespace std;

int main(int, char**) {

    cout << "Hello, World" << endl;

#ifdef DEBUG
    cout << "DEBUG BUILD" << endl;
#else
    cout << "RELEASE BUILD" << endl;
#endif
}