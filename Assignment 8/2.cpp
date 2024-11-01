#include <iostream>
#include <string>
#include <complex>
using namespace std;
template <typename T>
class Node {
public:
T data;
Node* next;
Node(T value) : data(value), next(nullptr) {}
};
template <typename T>
class LinkedList {
private:
Node<T>* head;
public:
LinkedList() : head(nullptr) {}
void append(T value) {
Node<T>* newNode = new Node<T>(value);
if (!head) {
head = newNode;
return;}
Node<T>* temp = head;
while (temp->next) {
temp = temp->next;}
temp->next = newNode;
}
void display() const {
Node<T>* temp = head;
while (temp) {
cout << temp->data << " -> ";
temp = temp->next;}
cout << "nullptr" << endl;}
~LinkedList() {
Node<T>* current = head;
while (current) {
Node<T>* nextNode = current->next;
delete current;
current = nextNode;}}
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
regnNo): name(name), rollNo(rollNo), year(year), gender(gender), cgpa(cgpa), regnNo(regnNo) {}
friend ostream& operator<<(ostream& os, const Student& student) {
os << "Name: " << student.name << ", Roll No: " << student.rollNo<< ", Year: " << student.year <<
", Gender: " << student.gender
<< ", CGPA: " << student.cgpa << ", Regn No: " << student.regnNo;
return os;}
};
int main() {
LinkedList<int> intList;
intList.append(10);
intList.append(20);
intList.append(30);
cout << "Integer Linked List: ";
intList.display();
LinkedList<char> charList;
charList.append('A');
charList.append('B');
charList.append('C');
cout << "Character Linked List: ";
charList.display();
LinkedList<float> floatList;
floatList.append(3.14f);
floatList.append(2.71f);
floatList.append(1.41f);
cout << "Float Linked List: ";
floatList.display();
LinkedList<complex<float>> complexList;
complexList.append(complex<float>(1, 2));
complexList.append(complex<float>(3, 4));
complexList.append(complex<float>(5, 6));
cout << "Complex Linked List: ";
complexList.display();
LinkedList<Student> studentList;
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
studentList.append(student);}
cout << "\nStudent Linked List: ";
studentList.display();
return 0;
}
