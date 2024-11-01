#include <iostream>
#include <stdexcept>
#include <numeric>
using namespace std;
class Fraction {
private:
 int numerator;
 int denominator;
 void reduce() {
 int gcd = std::gcd(numerator, denominator);
 numerator /= gcd;
 denominator /= gcd;
 if (denominator < 0) {
 numerator = -numerator;
 denominator = -denominator;}
}
public:
 Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) { //const
 if (denom == 0) {
 throw invalid_argument("Denominator cannot be zero");
 }
 reduce(); }
 Fraction(const Fraction &other) : numerator(other.numerator),
denominator(other.denominator) {} //copy const
 Fraction operator+(const Fraction &other) const { //add
 int num = numerator * other.denominator + other.numerator * denominator;
 int denom = denominator * other.denominator;
 return Fraction(num, denom);
 }
 Fraction operator-(const Fraction &other) const { //sub
 int num = numerator * other.denominator - other.numerator * denominator;
 int denom = denominator * other.denominator;
 return Fraction(num, denom);
 }
 Fraction operator*(const Fraction &other) const { //multi
 int num = numerator * other.numerator;
 int denom = denominator * other.denominator;
 return Fraction(num, denom);
 }
 Fraction operator/(const Fraction &other) const { //divi
 if (other.numerator == 0) {
 throw invalid_argument("Cannot divide by zero");
 }
 int num = numerator * other.denominator;
 int denom = denominator * other.numerator;
 return Fraction(num, denom);
 }
 bool operator==(const Fraction &other) const {
 return numerator == other.numerator && denominator == other.denominator; //equ
 }
 bool operator!=(const Fraction &other) const {
 return !(*this == other);
 }
 bool operator<(const Fraction &other) const {
 return numerator * other.denominator < other.numerator * denominator; //not eq
 }
 bool operator>(const Fraction &other) const {
 return other < *this;
 }
 Fraction& operator=(const Fraction &other) {
 if (this == &other) {
 return *this;
 }
 numerator = other.numerator;
 denominator = other.denominator;
 return *this;
 }
 friend ostream& operator<<(ostream &out, const Fraction &frac) { //prints
 out << frac.numerator;
 if (frac.denominator != 1) {
 out << "/" << frac.denominator;
 }
 return out;
 }
 friend istream& operator>>(istream &in, Fraction &frac) { //input or reads
 cout << "Enter numerator: ";
 in >> frac.numerator;
 cout << "Enter denominator: ";
 in >> frac.denominator;
 if (frac.denominator == 0) {
 throw invalid_argument("Denominator cannot be zero");
 }
 frac.reduce();
 return in; }
};
int main() {
 Fraction f1, f2;
 cout << "Enter first fraction:/n";
 cin >> f1;
 cout << "Enter second fraction:/n";
 cin >> f2;
 Fraction sum = f1 + f2;
 Fraction diff = f1 - f2;
 Fraction prod = f1 * f2;
 Fraction quot = f1 / f2;
 cout << "f1: " << f1 << endl;
 cout << "f2: " << f2 << endl;
 cout << "Sum: " << sum << endl;
 cout << "Difference: " << diff << endl;
 cout << "Product: " << prod << endl;
 cout << "Quotient: " << quot << endl;
 if (f1 == f2) {
 cout << "f1 is equal to f2" << endl;
 } else if (f1 != f2) {
 cout << "f1 is not equal to f2" << endl;
 }
 if (f1 < f2) {
 cout << "f1 is less than f2" << endl;
 } else if (f1 > f2) {
 cout << "f1 is greater than f2" << endl;
 }
 return 0;
}
