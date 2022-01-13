/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project1A

This program asks the user to input an integer in the range 0<n<100.
Then it will check if the input is out of range.
It will keep asking for input until a valid number is entered.
When a valid input is given it will output that number squared.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Please enter an integer: ";
    cin >> n;
    while (n <= 0 || n >= 100)
    {
        cout << "Please re-enter: ";
        cin >> n;
    }
    int square = n*n;
    cout << "Number squared is " << square << endl;
    return 0;
}