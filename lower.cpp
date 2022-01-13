/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yee
Assignment: Lower triangle

Write a program lower.cpp 
that prints the bottom-left
half of a square, given the 
side length.
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Input side length: ";
    cin >> n;
    cout << "Shape: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for( int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}