#include <iostream>
#include <memory>

class Base {
public:
    virtual ~Base() { std::cout << "Base destructor\n"; }
};

class Derived : public Base {
public:
    ~Derived() override { std::cout << "Derived destructor\n"; }
};

int main() {
    std::unique_ptr<Base> pointer = std::make_unique<Derived>();
    return 0;
}