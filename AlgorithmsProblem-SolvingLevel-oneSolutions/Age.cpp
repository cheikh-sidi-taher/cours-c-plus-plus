#include <iostream>
using namespace std;



int ReadAge(){
    int age;
    cout<<"Enter your age: ";
    cin>>age;
    return age;
}

bool ValidateNumberInRange(int Number, int from, int to){
    return Number >= from && Number <= to;
}

void PrintResult(int age){
    if(ValidateNumberInRange(age, 18, 45)){
        cout << "Valid Age" << endl;
    }else{
        cout << "Invalid Age" << endl;
    }
}
int main()
{
   PrintResult(ReadAge());
   return 0;
}