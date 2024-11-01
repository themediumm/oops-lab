#include <iostream>
class Stack {
private:
 int* arr;
 int top;
 int capacity;
public:
 Stack(int capacity) {
 arr = new int[capacity];
 top = -1;
 }
 ~Stack() {
 delete[] arr;
 }
 void push(int val) {
 if (isFull()) {
 std::cout << "Stack is full" << val << std::endl;
 return;
 }
 arr[++top] = val;
 }
 int pop() {
 if (isEmpty()) {
 std::cout << "Stack is empty" << std::endl;
 return -1;
 }
 return arr[top--];
 }
 bool isEmpty() {
 return top == -1;
 }
 bool isFull() {
 return top == capacity - 1;
 }
 void display() {
 if (isEmpty()) {
 std::cout << "Stack is empty" << std::endl;
 return;
 }
 std::cout << "Stack elements: ";
 for (int i = 0; i <= top; i++) {
 std::cout << arr[i] << " ";
 }
 std::cout << std::endl;
 }
};
int main() {
 Stack stack(5);
 stack.push(1);
 stack.push(2);
 stack.push(3);
 stack.push(4);
 stack.push(5);
 stack.display();
 std::cout << "Popped element: " << stack.pop() << std::endl;
 std::cout << "Popped element: " << stack.pop() << std::endl;
 stack.display();
 return 0;
}
