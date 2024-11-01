#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
void indent(const string& inputFile, const string& outputFile) {
 ifstream fin(inputFile);
 ofstream fout(outputFile);
 string line;
 int tab = 0;
 while (getline(fin, line)) {
 string indentation(tab * 4, ' ');
 fout << indentation;
 fout << line << endl;
 if (line.find("{") != string::npos) {
 tab++;
 } else if (line.find("}") != string::npos) {
 tab--;
 }
 }
 fin.close();
 fout.close();
}
int main() {
 string inputFile = "unindented_code.cpp";
 string outputFile = "indented_code.cpp";
 indent(inputFile, outputFile);
 cout << "Indentation complete. Check " << outputFile << endl;
 return 0;
}
