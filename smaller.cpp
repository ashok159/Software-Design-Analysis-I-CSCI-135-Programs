/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab1A

This program asks the user to input two numbers. 
Then it will take both numbers and print which of the two is the smaller one.
*/

#include <iostream>
using namespace std;

int main()
{
    int first, second;
    cout << "Enter the first number: ";
    cin >> first;
    cout << "Enter the second number : ";
    cin >> second;
    if (first > second)
        cout << "The smaller of the two is: " << second << endl;
    else if (second > first)
        cout << "The smaller of the two is: " << first << endl;
    return 0;
}