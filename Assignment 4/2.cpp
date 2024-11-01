#include <iostream>
class Shape {
protected:
 double area;
public:
 Shape() {}
 Shape(double side) {
 area = side * side;
 }
 Shape(double length, double width) {
 area = length * width;
 }
 void displayArea() {
 std::cout << "Area: " << area << std::endl;
 }
};
int main() {
 Shape square(5.0);
 std::cout << "Square: ";
 square.displayArea();
 Shape rectangle(4.0, 6.0);
 std::cout << "Rectangle: ";
 rectangle.displayArea();
 return 0;
}
