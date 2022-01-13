/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab1A

This program asks the user to input an integer representing a year number. 
Then it will take the year entered and print whether that is a leap year or common year.
*/

#include <iostream>
using namespace std;

int main()
{
    int year;
    cout << "Enter year: ";
    cin >> year;
    if (year%4 != 0)
        cout << "Common year" << endl;
    else if (year%100 != 0)
        cout << "Leap year" << endl;
    else if (year%400 != 0)
        cout << "Common year" << endl;
    else 
        cout << "Leap year" << endl;
    return 0;
}