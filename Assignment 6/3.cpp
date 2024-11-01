#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
string name;
int age;
public:
Person(string n, int a) : name(n), age(a) {}
void display() {
cout << "Name: " << name << endl;
cout << "Age: " << age << endl;
}
};
class Student : public Person {
private:
string studentID;
public:
Student(string n, int a, string id) : Person(n, a), studentID(id) {}
void display() {
Person::display();
cout << "Student ID: " << studentID << endl;
}
};
int main() {
string name, studentID;
int age;
cout << "Enter name: ";
getline(cin, name);
cout << "Enter age: ";
cin >> age;
cin.ignore();
cout << "Enter student ID: ";
getline(cin, studentID);
Student student(name, age, studentID);
cout << endl << "Student Information:" << endl;
student.display();
return 0;
}