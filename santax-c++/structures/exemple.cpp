#include <iostream>
using namespace std;

struct Car {
   string Brand;
   string Model;
   int Year;
};



int main(){

    Car myCar1 , myCar2;
    myCar1.Brand = "BMW";
    myCar1.Model = "M3";
    myCar1.Year = 2020;
    

    myCar2.Brand = "Mercedes";
    myCar2.Model = "E200";
    myCar2.Year = 2021;

    cout << myCar1.Brand << " " << myCar1.Model << " " << myCar1.Year << endl;
    cout << myCar2.Brand << " " << myCar2.Model << " " << myCar2.Year << endl;
}
