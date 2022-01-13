/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab1B

This program asks the user for three numbers.
It then compares the first two and finds the smaller of the two.
Finally it takes the smallest of those and compares it with the third number to find the smallest of all three.
*/

#include <iostream>
using namespace std;

int main()
{
    int first, second, third;
    cout << "Enter the first number: ";
    cin >> first;
    cout << "Enter the second number : ";
    cin >> second;
    cout << "Enter the third number: ";
    cin >> third;
    if (first > second)
    {
        if (second > third)
            cout << "The smaller of the three is " << third << endl;
        else if (second < third)
            cout << "The smaller of the three is " << second << endl;
    }
    else if (second > first)
    {
        if (first > third)
            cout << "The smaller of the three is" << third << endl;
        else if (first < third)
            cout << "The smaller of the three is " << first << endl;
    }
    return 0;
}