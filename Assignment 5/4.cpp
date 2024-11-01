#include<iostream>
class Coordinates{
private:
int x;
int y;
public:
Coordinates(int x=0,int y=0): x(x),y(y){} //def const
Coordinates operator-(){ //overload unary op
x--;
y--;
std::cout<<"Decrementing X and Y :"<<x<<","<<y<<std::endl;
return *this;
}
void print(){
std::cout<<"X:"<<x<<"Y"<<y<<std::endl;
}
};
int main(){
Coordinates coord(9,13);
std::cout<<"initial coordinates:";
coord.print();
-coord;
std::cout<<"after decrement:";
coord.print();
return 0;
}