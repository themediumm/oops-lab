#include <iostream>
#include <string>
using namespace std;
class Vehicle {
protected:
int numberOfWheels;
float speed;
public:
Vehicle(int wheels, float spd) : numberOfWheels(wheels), speed(spd) {}
void display() {
cout << "Number of Wheels: " << numberOfWheels << endl;
cout << "Speed: " << speed << " km/h" << endl;
}
float getSpeed(){
return speed;
}
};
class Car : public Vehicle {
private:
int numberOfPassengers;
public:
Car(int wheels, float spd, int passengers): Vehicle(wheels, spd), numberOfPassengers(passengers)
{}
void display() {
cout << "Car Information: " << endl;
Vehicle::display();
cout << "Number of Passengers: " << numberOfPassengers << endl;
}
};
class Truck : public Vehicle {
private:
float loadLimit;
public:
Truck(int wheels, float spd, float limit): Vehicle(wheels, spd), loadLimit(limit) {}
void display() {
cout << "Truck Information: " << endl;
Vehicle::display();
cout << "Load Limit: " << loadLimit << " kg" << endl;
}
};
int main() {
int wheels;
float speed;
int passengers;
float loadLimit;
cout << "Enter number of wheels for the car: ";
cin >> wheels;
cout << "Enter speed for the car (km/h): ";
cin >> speed;
cout << "Enter number of passengers for the car: ";
cin >> passengers;
Car myCar(wheels, speed, passengers);
cout << "\nEnter number of wheels for the truck: ";
cin >> wheels;
cout << "Enter speed for the truck (km/h): ";
cin >> speed;
cout << "Enter load limit for the truck (kg): ";
cin >> loadLimit;
Truck myTruck(wheels, speed, loadLimit);
cout << endl;
myCar.display();
cout << endl;
myTruck.display();
cout << endl;
if (myCar.getSpeed() > myTruck.getSpeed()) {
cout << "The Car is faster than the Truck." << endl;
} else if (myCar.getSpeed() < myTruck.getSpeed()) {
cout << "The Car is slower than the Truck." << endl;
} else {
cout << "The Car and Truck have the same speed." << endl;
}
return 0;
}
