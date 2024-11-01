#include <iostream>
class Complex {
private:
 double real;
 double imag;
public:
 Complex(double r = 0, double i = 0) {
 real = r;
 imag = i;
 }
 Complex operator+(const Complex& other) {
 return Complex(real + other.real, imag + other.imag);
 }
 Complex operator-(const Complex& other) {
 return Complex(real - other.real, imag - other.imag);
 }
 void display() {
 std::cout << real << " + " << imag << "i" << std::endl;
 }
};
int main() {
 Complex num1(3.0, 4.0);
 Complex num2(2.0, 1.0);
 std::cout << "Complex Number 1: ";
 num1.display();
 std::cout << "Complex Number 2: ";
 num2.display();
 Complex sum = num1 + num2;
 std::cout << "Sum: ";
 sum.display();
 Complex difference = num1 - num2;
 std::cout << "Difference: ";
 difference.display();
 return 0;
}
