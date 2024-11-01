#include <iostream>
using namespace std;
class Matrix {
protected:
int arr[3][3];
public:
Matrix() {
for (int i = 0; i < 3; i++)
for (int j = 0; j < 3; j++)
arr[i][j] = 0;
}
void show() {
cout << "Matrix: " << endl;
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++)
cout << arr[i][j] << " ";
cout << endl;
}
}
void read() {
cout << "Enter elements for 3x3 matrix:" << endl;
for (int i = 0; i < 3; i++)
for (int j = 0; j < 3; j++)
cin >> arr[i][j];
}
};
class MatrixA : public Matrix {
public:
void show(){
cout << "MatrixA: " << endl;
Matrix::show();
}
};
class MatrixB : public MatrixA {
public:
void show(){
cout << "MatrixB: " << endl;
MatrixA::show();
}
};
int main() {
Matrix matrix;
MatrixA matrixA;
MatrixB matrixB;
matrix.read();
matrixA.read();
matrixB.read();
matrix.show();
matrixA.show();
matrixB.show();
return 0;
}
