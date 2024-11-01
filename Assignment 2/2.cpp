#include <iostream>
using namespace std;
class Heap {
private:
 int* heap;
 int capacity;
 int size;
 void heapifyUp(int index) {
 if (index && heap[parent(index)] < heap[index]) {
 swap(heap[index], heap[parent(index)]);
 heapifyUp(parent(index));
 }
 }
 void heapifyDown(int index) {
 int left = leftChild(index);
 int right = rightChild(index);
 int largest = index;
 if (left < size && heap[left] > heap[index])
 largest = left;
 if (right < size && heap[right] > heap[largest])
 largest = right;
 if (largest != index) {
 swap(heap[index], heap[largest]);
 heapifyDown(largest);
 }
 }
 int parent(int index) {
 return (index - 1) / 2;
 }
 int leftChild(int index) {
 return (2 * index + 1);
 }
 int rightChild(int index) {
 return (2 * index + 2);
 }
public:
 Heap(int capacity) {
 this->capacity = capacity;
 this->size = 0;
 heap = new int[capacity];
 }
 void insert(int value) {
 if (size == capacity) {
 cout << "Heap is full. Cannot insert." << endl;
 return;
 }
 heap[size] = value;
 size++;
 heapifyUp(size - 1);
 }
 int findMax() {
 if (size == 0) {
 cout << "Heap is empty." << endl;
 return -1;
 }
 return heap[0];
 }
 int extractMax() {
 if (size == 0) {
 cout << "Heap is empty." << endl;
 return -1;
 }
 int max = heap[0];
 heap[0] = heap[size - 1];
 size--;
 heapifyDown(0);
 return max;
 }
 void deleteMax() {
 if (size == 0) {
 cout << "Heap is empty." << endl;
 return;
 }
 heap[0] = heap[size - 1];
 size--;
 heapifyDown(0);
 }
 void replace(int index, int value) {
 if (index >= size) {
 cout << "Invalid index." << endl;
 return;
 }
 heap[index] = value;
 heapifyUp(index);
 heapifyDown(index);
 }
};
int main() {
 Heap heap(10);
 heap.insert(10);
 heap.insert(20);
 heap.insert(30);
 heap.insert(40);
 heap.insert(50);
 cout << "Max: " << heap.findMax() << endl;
 cout << "Extract Max: " << heap.extractMax() << endl;
 heap.deleteMax();
 heap.replace(0, 60);
 cout << "Max after replace: " << heap.findMax() << endl;
 return 0;
}
