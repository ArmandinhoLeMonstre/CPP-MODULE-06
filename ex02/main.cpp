#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate() 
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    int r = std::rand() % 3;
    if (r == 0) {
        std::cout << "[Generated A] ";
        return new A;
    } else if (r == 1) {
        std::cout << "[Generated B] ";
        return new B;
    } else {
        std::cout << "[Generated C] ";
        return new C;
    }
}

void identify(Base* p) 
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type: A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "Type: B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "Type: C\n";
    else
        std::cout << "Type: Unknown\n";
}

void identify(Base& p) 
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type: A\n";
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type: B\n";
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type: C\n";
        return;
    } catch (...) {}

    std::cout << "Type: Unknown\n";
}

int main() {
    Base* obj = generate();

    std::cout << "identify(Base*): ";
    identify(obj);

    std::cout << "identify(Base&): ";
    identify(*obj);

    delete obj;
    return 0;
}
