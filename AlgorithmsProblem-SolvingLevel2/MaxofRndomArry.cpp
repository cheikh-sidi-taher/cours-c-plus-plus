#include <iostream>
using namespace std;

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

int MaxNumberInArray(int arr[100], int arrLength)
{
    int max = 0;
    for (int i = 1; i < arrLength; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[100], arrLength;
    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);
    cout << "\nMax Number is : ";
    cout << MaxNumberInArray(arr, arrLength) << endl;
    return 0;
}