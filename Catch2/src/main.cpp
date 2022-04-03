#include <iostream>
#include "foo.hpp"

int main(int, char**) {

    std::cout << "Hello, World, 1 + 1 = " << add(1,1) <<std::endl;

#ifdef DEBUG
    std::cout << "DEBUG BUILD" << std::endl;
#else
    std::cout << "RELEASE BUILD" << std::endl;
#endif
}