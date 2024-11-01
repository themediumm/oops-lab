#include <iostream>
using namespace std;
class Node {
public:
int data;
Node* next;
Node(int value) : data(value), next(nullptr) {}
};
class LinkedList {
private:
Node* head;
int size;
public:
LinkedList() : head(nullptr), size(0) {}
LinkedList(LinkedList& other) : head(nullptr), size(0) {
Node* current = other.head;
while (current) {
append(current->data);
current = current->next;
}
}
~LinkedList() {
clear();
}
void append(int value) {
Node* newNode = new Node(value);
if (!head) {
head = newNode;
} else {
Node* current = head;
while (current->next) {
current = current->next;
}
current->next = newNode;
}
size++;
}
LinkedList operator+(LinkedList& other){
LinkedList result(*this);
Node* current = other.head;
while (current) {
result.append(current->data);
current = current->next;
}
return result;
}
void reverse() {
Node* prev = nullptr;
Node* current = head;
Node* next = nullptr;
while (current) {
next = current->next;
current->next = prev;
prev = current;
current = next;
}
head = prev;
}
bool operator==(LinkedList& other){
if (size != other.size) return false;
Node* current1 = head;
Node* current2 = other.head;
while (current1 && current2) {
if (current1->data != current2->data) return false;
current1 = current1->next;
current2 = current2->next;
}
return true;
}
LinkedList& operator=(LinkedList& other) {
if (this == &other) return *this;
clear();
Node* current = other.head;
while (current) {
append(current->data);
current = current->next;
}
return *this;
}
int& operator[](int index) {
if (index >= size) {
cerr << "Index out of bounds!" << endl;
throw out_of_range("Index out of bounds!");
}
Node* current = head;
for (int i = 0; i < index; i++) {
current = current->next;
}
return current->data;
}
friend istream& operator>>(istream& in, LinkedList& list) {
int value;
while (in >> value) {
list.append(value);
}
return in;
}
friend ostream& operator<<(ostream& out,LinkedList& list) {
Node* current = list.head;
out << "[ ";
while (current) {
out << current->data << " ";
current = current->next;
}
out << "]";
return out;
}
void clear() {
while (head) {
Node* temp = head;
head = head->next;
delete temp;
}
size = 0;
}
int getSize() const {
return size;
}
};
int main() {
LinkedList list1, list2;
cout << "Enter values for list 1 (end with non-numeric input): ";
cin >> list1;
cout << "Enter values for list 2 (end with non-numeric input): ";
cin.clear();
cin.ignore();
cin >> list2;
cout << "List 1: " << list1 << endl;
cout << "List 2: " << list2 << endl;
LinkedList concatenatedList = list1 + list2;
cout << "Concatenated List: " << concatenatedList << endl;
list1.reverse();
cout << "Reversed List 1: " << list1 << endl;
if (list1 == list2) {
cout << "List 1 and List 2 are equal." << endl;
} else {
cout << "List 1 and List 2 are not equal." << endl;
}
int index;
cout << "Enter index to access in List 1: ";
cin >> index;
try {
cout << "Element at index " << index << ": " << list1[index] << endl;
} catch (const out_of_range& e) {
cerr << e.what() << endl;
}
return 0;
}