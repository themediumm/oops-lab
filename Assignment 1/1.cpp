#include<iostream>
using namespace std;
int main() {
 int n;
 cout << "Enter the number of lines (n must be odd): ";
 cin >> n;
 for (int i = 1; i <= n / 2 + 1; i++) {
 for (int j = 1; j <= n / 2 - i + 1; j++) {
 cout << " ";
 }
 for (int j = 1; j <= 2 * i - 1; j++) {
 cout << j;
 }
 cout << endl;
 }
 for (int i = n / 2; i >= 1; i--) {
 for (int j = 1; j <= n / 2 - i + 1; j++) {
 cout << " ";
 }
 for (int j = 1; j <= 2 * i - 1; j++) {
 cout << j;
 }
 cout << endl;
 }
 return 0;
}
