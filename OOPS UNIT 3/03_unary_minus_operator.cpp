#include <iostream>

class Number {
private:
    int value;
public:
    explicit Number(int givenValue) : value(givenValue) {}
    Number operator-() const { return Number(-value); }
    void display() const { std::cout << value << '\n'; }
};

class Balance {
private:
    double amount;
public:
    explicit Balance(double value) : amount(value) {}
    Balance operator-() const { return Balance(-amount); }
    void display() const { std::cout << amount << '\n'; }
};

int main() {
    Number first(25);
    Number second = -first;
    std::cout << "Original value: "; first.display();
    std::cout << "Negated value: "; second.display();

    Balance balance(1500.50);
    std::cout << "Original balance: "; balance.display();
    std::cout << "Negative balance: "; (-balance).display();
    return 0;
}