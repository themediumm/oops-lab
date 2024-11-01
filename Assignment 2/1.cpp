#include <iostream>
using namespace std;
class Node {
public:
 int data;
 Node* next;
};
class LinkedList {
private:
 Node* head;
public:
 LinkedList() {
 head = nullptr;
 }
 void insertBeg(int value) {
 Node* newNode = new Node();
 newNode->data = value;
 newNode->next = head;
 head = newNode;
 }
 void deleteKey(int key) {
 if (head == nullptr) return;
 if (head->data == key) {
 Node* temp = head;
 head = head->next;
 delete temp;
 return;
 }
 Node* current = head;
 while (current->next != nullptr) {
 if (current->next->data == key) {
 Node* temp = current->next;
 current->next = current->next->next;
 delete temp;
 return;
 }
 current = current->next;
 }
 }
 void display() {
 Node* current = head;
 while (current != nullptr) {
 cout << current->data << " ";
 current = current->next;
 }
 cout << endl;
 }
 void concatenate(LinkedList& list2) {
 if (list2.head == nullptr) return;
 Node* current = head;
 while (current->next != nullptr) {
 current = current->next;
 }
 current->next = list2.head;
 }
 bool search(int key) {
 Node* current = head;
 while (current != nullptr) {
 if(current->data == key) {
 return true;
 }
 current = current->next;
 }
 return false;
 }
};
int main() {
 LinkedList list1;
 list1.insertBeg(10);
 list1.insertBeg(20);
 list1.insertBeg(30);
 LinkedList list2;
 list2.insertBeg(40);
 list2.insertBeg(50);
 list2.insertBeg(60);
 cout << "List 1: ";
 list1.display();
 cout << "List 2: ";
 list2.display();
 list1.concatenate(list2);
 cout << "Concatenated List: ";
 list1.display();
 cout << "Search for 20: " << (list1.search(20) ? "Found" : "Not Found") << endl;
 list1.deleteKey(20);
 cout << "List after deletion: ";
 list1.display();
 return 0;
}