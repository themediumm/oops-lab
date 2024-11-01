#include <iostream>
class Total_Cost {
private:
 double length;
 double breadth;
 double height;
 double costPerSquareMeter;
public:
 Total_Cost(double length, double breadth, double height, double costPerSquareMeter) {
 this->length = length;
 this->breadth = breadth;
 this->height = height;
 this->costPerSquareMeter = costPerSquareMeter;
 }
 double calculateTotalCost() {
 double totalArea = 2 * (length * height + breadth * height);
 double totalCost = totalArea * costPerSquareMeter;
 return totalCost;
 }
 void displayTotalCost() {
 double totalCost = calculateTotalCost();
 std::cout <<"Total cost to paint walls: "<< totalCost << std::endl;
 }
};
 int main() {
 Total_Cost room(1.0, 2.0, 8.0, 9.0);
 room.displayTotalCost();
 return 0;
}