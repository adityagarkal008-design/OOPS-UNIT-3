#include <iostream>

class Counter {
private:
    int value;
public:
    explicit Counter(int initialValue = 0) : value(initialValue) {}

    Counter& operator++() { ++value; return *this; }
    Counter operator++(int) { Counter old = *this; ++value; return old; }

    Counter& operator--() { --value; return *this; }
    Counter operator--(int) { Counter old = *this; --value; return old; }

    void display() const { std::cout << value << '\n'; }
};

int main() {
    Counter counter(5);

    ++counter;
    std::cout << "After prefix increment: "; counter.display();

    Counter oldValue = counter++;
    std::cout << "Value returned by postfix increment: "; oldValue.display();
    std::cout << "Counter after postfix increment: "; counter.display();

    --counter;
    std::cout << "After prefix decrement: "; counter.display();

    Counter oldDecrement = counter--;
    std::cout << "Value returned by postfix decrement: "; oldDecrement.display();
    std::cout << "Counter after postfix decrement: "; counter.display();

    return 0;
}