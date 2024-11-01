#include <iostream>
#include <vector>
class Set {
private:
 std::vector<int> elements;
public:
 Set() {}
 Set(std::initializer_list<int> init) {
 for (int elem : init) {
 elements.push_back(elem);
 }
 }
 Set(const Set& other) {
 elements = other.elements;
 }
 bool isMember(int elem) {
 for (int e : elements) {
 if (e == elem) {
 return true;
 }
 }
 return false;
 }
 void insertSet(int elem) {
 if (!isMember(elem)) {
 elements.push_back(elem);
 }
 }
 void delSet(int elem) {
 for (auto it = elements.begin(); it != elements.end(); ++it) {
 if (*it == elem) {
 elements.erase(it);
 return;
 }
 }
 }
 Set unionSet(const Set& other) {
 Set result = *this;
 for (int elem : other.elements) {
 result.insertSet(elem);
 }
 return result;
 }
 Set intersection(const Set& other) {
 Set result;
 for (int elem : elements) {
 if (other.isMember(elem)) {
 result.insertSet(elem);
 }
 }
 return result;
 }
 Set complement(const Set& universalSet) {
 Set result;
 for (int elem : universalSet.elements) {
 if (!isMember(elem)) {
 result.insertSet(elem);
 }
 }
 return result;
 }
 void printSet() {
 std::cout << "{";
 for (int elem : elements) {
 std::cout << elem << " ";
 }
 std::cout << "}" << std::endl;
 }
};
int main() {
 Set set1;
 Set set2 = {1, 2, 3, 4, 5};
 Set set3 = set2;
 set1.insertSet(1);
 set1.insertSet(2);
 set1.insertSet(3);
 set2.delSet(3);
 Set unionSet = set1.unionSet(set2);
 Set intersectionSet = set1.intersection(set2);
 Set universalSet = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 Set complementSet = set1.complement(universalSet);
 std::cout << "Set 1: ";
 set1.printSet();
 std::cout << "Set 2: ";
 set2.printSet();
 std::cout << "Set 3: ";
 set3.printSet();
 std::cout << "Union Set: ";
 unionSet.printSet();
 std::cout << "Intersection Set: ";
 intersectionSet.printSet();
 std::cout << "Complement Set: ";
 complementSet.printSet();
 return 0;
}
