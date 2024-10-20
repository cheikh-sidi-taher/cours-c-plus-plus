#include <iostream>
using namespace std;

enum Color {RED, GREEN, BLUE, YELLOW};
enum Day {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
enum Direction {UP, DOWN, LEFT, RIGHT};
enum Gender {MALE, FEMALE};
enum Status {ACTIVE, INACTIVE};
int main(){


    Color myColor ;
    Day myDay;
    Direction myDirection;
    Gender myGender;
    Status myStatus;

    myColor = Color::RED;
    myDay = Day::SUNDAY;
    myDirection = Direction::UP;
    myGender = Gender::MALE;
    myStatus = Status::INACTIVE;


    cout << "myColor = " << myColor << endl;
    cout << "myDay = " << myDay << endl;
    cout << "myDirection = " << myDirection << endl;
    cout << "myGender = " << myGender << endl;
    cout << "myStatus = " << myStatus << endl;
   
}