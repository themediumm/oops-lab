#include <iostream>
class Number {
private:
 double num;
public:
 Number(double n) {
 num = n;
 }
 Number operator+(const Number& other) {
 return Number(num + other.num);
 }
 Number operator-(const Number& other) {
 return Number(num - other.num);
 }
 Number operator*(const Number& other) {
 return Number(num * other.num);
 }
 Number operator/(const Number& other) {
 if (other.num != 0) {
 return Number(num / other.num);
 } else {
 std::cout << "Error: Division by zero!" << std::endl;
 return Number(0);
 }
 }
 void display() {
 std::cout << num << std::endl;
 }
};
int main() {
 Number num1(10.0);
 Number num2(2.0);
 Number sum = num1 + num2;
 std::cout << "Sum: ";
 sum.display();
 Number difference = num1 - num2;
 std::cout << "Difference: ";
 difference.display();
 Number product = num1 * num2;
 std::cout << "Product: ";
 product.display();
 Number quotient = num1 / num2;
 std::cout << "Quotient: ";
 quotient.display();
 return 0;
}