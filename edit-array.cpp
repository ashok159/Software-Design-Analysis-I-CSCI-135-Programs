/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab1A

This program creates an array of 10 integers.
It then fills all the cells with with value 1 using a for loop.
It will print all elements of the array on the screen and ask the user to input the cell index and its new value.
If the index is within range, it will update the asked cell and go back to step 3, otherwise it'll end.
*/

#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int n = 10;
    int i;
    int v;
    do{
        for (int t = 0; t < n; t++)
            cout << arr[t] << " ";
        cout << endl;
        cout << "Input index ";
        cin >> i;
        cout << "Input value ";
        cin >> v;
        if ((i >= 0) && (i < 10))
            arr[i] = v;
    } while ((i >= 0) && (i < 10));
    return 0;
}