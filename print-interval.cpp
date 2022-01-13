/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project1A

This program asks the user to input two integers L and U.
These represent the upper and lower limits of an interval.
It will then print out all integers in the range L <= i < U.
*/

#include <iostream>
using namespace std;
int main()
{
    int L,U;
    cout << "Please enter L: ";
    cin >> L;
    cout << "Please enter U: ";
    cin >> U;
    for (int i = L; i < U; i++)
        cout << i << " ";
    return 0;
}