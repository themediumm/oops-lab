#include <iostream>
#include <string>
using namespace std;
class Employee {
protected:
string name;
int id;
double salary;
public:
Employee(string& name, int id, double salary) : name(name), id(id), salary(salary) {}
virtual void displayInfo(){
cout << "Name: " << name << endl;
cout << "ID: " << id << endl;
cout << "Salary: $" << salary << endl;
}
double getSalary(){
return salary;
}
};
class Manager : public Employee {
private:
int numEmployees;
public:
Manager(string& name, int id, double salary, int numEmployees) : Employee(name, id, salary),
numEmployees(numEmployees) {}
void displayInfo(){
Employee::displayInfo();
cout << "Number of Employees Managed: " << numEmployees << endl;
}
};
class Engineer : public Employee {
private:
string department;
public:
Engineer(string& name, int id, double salary,string& department) : Employee(name, id, salary),
department(department) {}
void displayInfo(){
Employee::displayInfo();
cout << "Department: " << department << endl;
}
};
int main() {
string name;
int id, numEmployees;
double salary;
cout << "Enter Manager's Name: ";
getline(cin, name);
cout << "Enter Manager's ID: ";
cin >> id;
cout << "Enter Manager's Salary: ";
cin >> salary;
cout << "Enter Number of Employees Managed: ";
cin >> numEmployees;
cin.ignore();
Manager manager(name, id, salary, numEmployees);
cout << "\nEnter Engineer's Name: ";
getline(cin, name);
cout << "Enter Engineer's ID: ";
cin >> id;
cout << "Enter Engineer's Salary: ";
cin >> salary;
cin.ignore();
string department;
cout << "Enter Engineer's Department: ";
getline(cin, department);
Engineer engineer(name, id, salary, department);
cout << "\nManager Details:\n";
manager.displayInfo();
cout << "\nEngineer Details:\n";
engineer.displayInfo();
cout << "\nSalary Comparison:\n";
if (manager.getSalary() > engineer.getSalary()) {
cout << "Manager earns more than Engineer." << endl;
} else if (manager.getSalary() < engineer.getSalary()) {
cout << "Engineer earns more than Manager." << endl;
} else {
cout << "Both earn the same salary." << endl;
}
return 0;
}
