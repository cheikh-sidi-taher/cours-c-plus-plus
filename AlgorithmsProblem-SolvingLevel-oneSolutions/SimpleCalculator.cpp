#include <iostream>
#include <string>
using namespace std;

enum enOperationType {
    Add = '+',
    Subtract = '-',
    Multiply = '*',
    Divide = '/'
};
float ReadNumber(string Message)
{
    float number= 0;
    cout << Message << endl;
    cin >> number;
    return number;
}


enOperationType ReadOperation()
{
    char OT = '+';
    cout << "Please enter your operation: " << endl;
    cin >> OT;
    return (enOperationType)OT;
}

float Calculate(float number1, float number2, enOperationType OpType){
    switch (OpType)
    {
   case enOperationType::Add:
        return number1 + number2;
        break;
    case enOperationType::Subtract:
        return number1 - number2;
        break;
    case enOperationType::Multiply:
        return number1 * number2;
        break;
    case enOperationType::Divide:
        return number1 / number2;
        break;
    default:
        break;
    }
}

int main()
{
    float number1 = ReadNumber("Please enter first number: ");
    float number2 = ReadNumber("Please enter second number: ");
    enOperationType OpType = ReadOperation();
    cout << "Result: " << Calculate(number1, number2, OpType) << endl;
    return 0;
}