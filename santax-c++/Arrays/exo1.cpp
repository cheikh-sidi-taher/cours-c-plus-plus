#include <iostream>
#include <cmath>
using namespace std;

void ReadArray(int arr[100], int arrLength){
    cout << "Enter array elements: \n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        cin >> arr[i];}


void  PrintArray(int arr[100], int arrLength){    
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";  }


void CopyArray(int arrSource[100], int arrDestination[100], int arrLength){
    for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[i];}

int main(){
    int arrSource[100], arrDestination[100], arrLength;
    ReadArray(arrSource, arrLength);
    CopyArray(arrSource, arrDestination, arrLength);
    PrintArray(arrDestination, arrLength);
}