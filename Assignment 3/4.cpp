#include <iostream>
#include <string>
class Book {
private:
 std::string title;
 std::string author;
 int year;
 double price;
public:
 Book(std::string title, std::string author, int year, double price) {
 this->title = title;
 this->author = author;
 this->year = year;
 this->price = price;
 }
 void displayDetails() {
 std::cout << "Title: "<< title << std::endl;
 std::cout << "Author: "<< author << std::endl;
 std::cout << "Year: "<< year << std::endl;
 std::cout << "Price: "<< price << std::endl;
 }
 void applyDiscount() {
 price *= 0.05;
 }
 void updatePrice(double newPrice) {
 price = newPrice;
 }
 double getPrice() {
 return price;
 }
};
int main() {
 Book book("harry potter", "jk rowling", 2006, 500);
 book.displayDetails();
 book.applyDiscount();
 std::cout << "Price after discount: " << book.getPrice() << std::endl;

 book.updatePrice(475);
 std::cout << "Updated price: " << book.getPrice() << std::endl;
 return 0;
}