#include <iostream>
using namespace std;
int RandomNumber(int From, int To)
{
  // Function to generate a random number
  int randNum = rand() % (To - From + 1) + From;
  return randNum;
}
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
  cout << "\nEnter number of elements:\n";
  cin >> arrLength;
  for (int i = 0; i < arrLength; i++)
    arr[i] = RandomNumber(1, 100);
}
void PrintArray(int arr[100], int arrLength)
{
  for (int i = 0; i < arrLength; i++)
    cout << arr[i] << " ";
  cout << "\n";
}
void AddArrayElement(int Number, int arr[100], int &arrLength)
{
  // its a new element so we need to add the length by 1
  arrLength++;
  arr[arrLength - 1] = Number;
}



int CountOddNumberInArray(int arr[100], int arrLength)
{
  int count = 0;
  for (int i = 0; i < arrLength; i++)
    if (arr[i] % 2 != 0)
      count++;
  return count;
}
void CoppyOddNumberInArray(int arr[100], int arr2[100], int arrLength, int &arr2Length)
{
  for (int i = 0; i < arrLength; i++)
    if (arr[i] % 2 != 0)
      AddArrayElement(arr[i], arr2, arr2Length);
}
// void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
// {
//   for (int i = 0; i < arrLength; i++)
//     AddArrayElement(arrSource[i], arrDestination,
//                     arrDestinationLength);
// }
int main()
{
  // Seeds the random number generator in C++, called only once
  srand((unsigned)time(NULL));
  int arr[100], arrLength = 0, arr2Length = 0;
  FillArrayWithRandomNumbers(arr, arrLength);
  PrintArray(arr, arrLength);
  cout << "Number of odd numbers: " << CountOddNumberInArray(arr, arrLength) << "\n";
  int arr2[100];
  CoppyOddNumberInArray(arr, arr2, arrLength, arr2Length);
  PrintArray(arr2, arr2Length);
}