/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yee
Assignment: Upper triangle

Write a program upper.cpp 
that prints the top-right 
half of a square, given 
the side length.
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Input side length: ";
    cin >> n;
    cout << "Shape: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            if (j < i)
                cout << " ";
            else 
                cout << "*";
        }
        cout << endl;
    }
    return 0;
}