#include <iostream>
#include <list>
using namespace std;
int hashFunction(int key) {
 return key % 10;
}
class HashTable {
private:
 int size;
 list<int>* table;
public:
 HashTable(int size) {
 this->size = size;
 table = new list<int>[size];
 }
 void insert(int key) {
 int index = hashFunction(key);
 table[index].push_back(key);
 }
 bool search(int key) {
 int index = hashFunction(key);
 for (int i : table[index]) {
 if (i == key) {
 return true;
 }
 }
 return false;
 }
 void deleteKey(int key) {
 int index = hashFunction(key);
 table[index].remove(key);
 }
 void display() {
 for (int i = 0; i < size; i++) {
 cout << "Bucket " << i << ": ";
 for (int j : table[i]) {
 cout << j << " ";
 }
 cout << endl;
 }
 }
 // Calculate load in each bucket
 void calculateLoad() {
 int totalKeys = 0;
 for (int i = 0; i < size; i++) {
 totalKeys += table[i].size();
 }
 for (int i = 0; i < size; i++) {
 float load = (float)table[i].size() / totalKeys * 100;
 cout << "Bucket " << i << ": " << load << "%" << endl;
 }
 }
};
int main() {
 HashTable hashTable(10);
 for (int i = 0; i < 100; i++) {
 hashTable.insert(rand() % 100);
 }
 cout << "Search key 50: " << (hashTable.search(50) ? "Found" : "Not found") << endl;
 hashTable.deleteKey(50);
 hashTable.display();
 hashTable.calculateLoad();
 return 0;
}