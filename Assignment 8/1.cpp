#include <iostream>
#include <string>
#include <complex>
using namespace std;
template <typename T>
class Stack{
private:
struct StackNode {
T data;
StackNode* next;
StackNode(T value) : data(value), next(nullptr){}};
StackNode* top;
public:
Stack() : top(nullptr) {}
void push(T value) {
StackNode* newNode = new StackNode(value);
newNode->next = top;
top = newNode;}
T pop() {
if (isEmpty()) {
cout<<"Stack is empty"<<"\n";}
T value = top->data;
StackNode* temp = top;
top = top->next;
delete temp;
return value;}
T peek(){
if (isEmpty()) {
cout<<"Stack is empty"<<"\n";}
return top->data;}
bool isEmpty(){
return top == nullptr;}
~Stack() {
while (!isEmpty()) {
pop();}}
};
class Student {
public:
string name;
string rollNo;
int year;
char gender;
float cgpa;
string regnNo;
Student(const string& name, const string& rollNo, int year, char gender, float cgpa, const string&
regnNo)
: name(name), rollNo(rollNo), year(year), gender(gender), cgpa(cgpa), regnNo(regnNo) {}
void display(){
cout << "Name: " << name << ", Roll No: " << rollNo << ", Year: " << year<< ", Gender: " <<
gender << ", CGPA: " << cgpa << ", Regn No: " << regnNo << endl;}
};
int main() {
Stack<int> intStack;
intStack.push(10);
intStack.push(20);
cout << "Popped from intStack: " << intStack.pop() << endl;
Stack<char> charStack;
charStack.push('A');
charStack.push('B');
cout << "Popped from charStack: " << charStack.pop() << endl;
Stack<float>floatStack;
floatStack.push(3.14f);
floatStack.push(2.71f);
cout << "Popped from floatStack: " << floatStack.pop() << endl;
Stack<complex<double>> ComplexStack;
ComplexStack.push(complex<double>(3.14,4.32));
ComplexStack.push(complex<double>(2.71,3.05));
cout << "Popped from ComplexStack: "<<ComplexStack.pop()<< endl;
Stack<Student> studentStack;
int numStudents;
cout << "Enter number of students: ";
cin >> numStudents;
cin.ignore();
for (int i = 0; i < numStudents; ++i) {
string name, rollNo, regnNo;
int year;
char gender;
float cgpa;
cout << "\nEntering details for student " << (i + 1) << ":\n";
cout << "Enter name: ";
getline(cin, name);
cout << "Enter roll number: ";
getline(cin, rollNo);
cout << "Enter year: ";
cin >> year;
cout << "Enter gender: ";
cin >> gender;
cout << "Enter CGPA: ";
cin >> cgpa;
cin.ignore();
cout << "Enter registration number: ";
getline(cin, regnNo);
Student student(name, rollNo, year, gender, cgpa, regnNo);
studentStack.push(student);}
cout << "\nStudents in stack:" << endl;
while (!studentStack.isEmpty()) {
Student student = studentStack.pop();
student.display();}
return 0;
}