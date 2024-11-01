#include <iostream>
using namespace std;
class Tool {
protected:
int strength;
char type;
public:
Tool(int str, char t) : strength(str), type(t) {}
void setStrength(int str) {
strength = str;
}
int getStrength(){
return strength;
}
char getType(){
return type;
}
};
class Rock : public Tool {
public:
Rock(int str) : Tool(str, 'r') {}
bool fight(Tool& opponent){
if (opponent.getType() == 's') {
return (strength * 2) > opponent.getStrength();
} else if (opponent.getType() == 'p') {
return (strength / 2) > opponent.getStrength();
}
return strength > opponent.getStrength();
}
};
class Paper : public Tool {
public:
Paper(int str) : Tool(str, 'p') {}
bool fight(Tool& opponent){
if (opponent.getType() == 'r') {
return (strength * 2) > opponent.getStrength();
} else if (opponent.getType() == 's') {
return (strength / 2) > opponent.getStrength();
}
return strength > opponent.getStrength();
}
};
class Scissors : public Tool {
public:
Scissors(int str) : Tool(str, 's') {}
bool fight(Tool& opponent){
if (opponent.getType() == 'p') {
return (strength * 2) > opponent.getStrength();
} else if (opponent.getType() == 'r') {
return (strength / 2) > opponent.getStrength();
}
return strength > opponent.getStrength();
}
};
int main() {
int rockStrength, paperStrength, scissorsStrength;
cout << "Enter strength for Rock: ";
cin >> rockStrength;
cout << "Enter strength for Paper: ";
cin >> paperStrength;
cout << "Enter strength for Scissors: ";
cin >> scissorsStrength;
Rock r1(rockStrength);
Paper p1(paperStrength);
Scissors s1(scissorsStrength);
cout << "Rock vs Scissors: " << (r1.fight(s1) ? "Rock wins" : "Scissors wins") << endl;
cout << "Scissors vs Paper: " << (s1.fight(p1) ? "Scissors wins" : "Paper wins") << endl;
cout << "Paper vs Rock: " << (p1.fight(r1) ? "Paper wins" : "Rock wins") << endl;
return 0;
}