#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main() {
 double thetaInitial, thetaFinal, stepCount, dampingFactor = 0.5;
 cout << "Enter the initial value of theta (in degrees): ";
 cin >> thetaInitial;
 cout << "Enter the final value of theta (in degrees): ";
 cin >> thetaFinal;
 cout << "Enter the step count: ";
 cin >> stepCount;
 double theta = thetaInitial;
 double stepSize = (thetaFinal - thetaInitial) / stepCount;
 cout << setw(10) << "Theta" << setw(15) << "Amplitude" << endl;
 cout << setw(25) << setfill('-') << "" << endl;
 cout << setfill(' ');
 for (int i = 0; i <= stepCount; i++) {
 double amplitude = exp(-dampingFactor * theta) * sin(theta * M_PI / 180);
 cout << setw(10) << theta << setw(15) << amplitude << endl;
 theta += stepSize;
 }
 return 0;
}