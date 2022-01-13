//Name: Ashok Surujdeo
//CSCI 135
//Lab Quiz 3

#include <iostream>
using namespace std;

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        cout << arr[i] << endl;
    return 0;
}