#include <iostream>
class Counter {
private:
 int count;
public:
 Counter() : count(0) {}
 Counter& operator++() {
 count++;
 return *this;
 }
 Counter operator++(int) {
 Counter temp = *this;
 count++;
 return temp;
 }
 int getCount() const {
 return count;
 }
};
int main() {
 Counter c;
 ++c;
 std::cout << "Prefix increment: " << c.getCount() << std::endl;
 c++;
 std::cout << "Postfix increment: " << c.getCount() << std::endl;
 return 0;
}