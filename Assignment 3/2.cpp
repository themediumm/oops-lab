#include <iostream>
class Queue {
private:
 int* arr;
 int front;
 int rear;
 int capacity;
public:
 Queue(int capacity) {
 this->capacity = capacity;
 arr = new int[capacity];
 front = 0;
 rear = 0;
 }
 ~Queue() {
 delete[] arr;
 }
 void push(int val) {
 if (isFull()) {
 std::cout << "Queue is full" << val << std::endl;
 return;
 }
 arr[rear] = val;
 rear = (rear + 1) % capacity;
 }
 int pop() {
 if (isEmpty()) {
 std::cout << "Queue is empty" << std::endl;
 return -1;
 }
 int val = arr[front];
 front = (front + 1) % capacity;
 return val;
 }
 bool isEmpty() {
 return front == rear;
 }
 bool isFull() {
 return (rear + 1) % capacity == front;
 }
 void display() {
 if (isEmpty()) {
 std::cout << "Queue is empty" << std::endl;
 return;
 }
 std::cout << "Queue elements: ";
 int temp = front;
 while (temp != rear) {
 std::cout << arr[temp] << " ";
 temp = (temp + 1) % capacity;
 }
 std::cout << std::endl;
 }
};
int main() {
 Queue queue(5);
 queue.push(1);
 queue.push(2);
 queue.push(3);
 queue.push(4);
 queue.push(5);
 queue.display();
 std::cout << "Popped element: " << queue.pop() << std::endl;
 std::cout << "Popped element: " << queue.pop() << std::endl;
 queue.display();
 return 0;
}
