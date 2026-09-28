#include <iostream>

class Complex {
private:
    int real;
    int imaginary;
public:
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    void display() const {
        std::cout << real << (imaginary >= 0 ? " + " : " - ")
                  << (imaginary >= 0 ? imaginary : -imaginary) << "i\n";
    }
};

int main() {
    Complex first(2, 3), second(4, 5);
    std::cout << "First: "; first.display();
    std::cout << "Second: "; second.display();
    std::cout << "Sum: "; (first + second).display();
    std::cout << "Difference: "; (first - second).display();
    return 0;
}