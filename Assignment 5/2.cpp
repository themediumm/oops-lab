#include <iostream>
class Complex {
private:
 double real;
 double imag;
public:
 Complex(double r = 0, double i = 0) : real(r), imag(i) {} //const
 Complex(const Complex& other) : real(other.real), imag(other.imag) {} //copy const
 Complex& operator=(const Complex& other) {
 if (this != &other) { //assign op
 real = other.real;
 imag = other.imag;
 }
 return *this;
 }
 Complex operator*(const Complex& other) const {
 return Complex(real * other.real - imag * other.imag, real * other.imag + imag *
other.real);//multi
 }
 Complex operator/(const Complex& other) const {
 double denominator = other.real * other.real + other.imag * other.imag;
 return Complex((real * other.real + imag * other.imag) / denominator, (imag * other.real -
real * other.imag) / denominator);//divi
 }
 Complex operator!() const {
 return Complex(real, -imag);//conj
 }
 bool operator==(const Complex& other) const {
 return real == other.real && imag == other.imag;
 }
 bool operator!=(const Complex& other) const {
 return !(*this == other);
 }
 void print() const {
 std::cout << real << " + " << imag << "i" << std::endl;
}
};
int main() {
 Complex c1(3, 4);
 Complex c2(7, 1);
 Complex product = c1 * c2;
 product.print();
 Complex quotient = c1 / c2;
 quotient.print();
 Complex conjugate = !c1;
 conjugate.print();
 if (c1 == c2) {
 std::cout << "c1 and c2 are equal" << std::endl;
 } else {
 std::cout << "c1 and c2 are not equal" << std::endl;
 }
 return 0;
}
