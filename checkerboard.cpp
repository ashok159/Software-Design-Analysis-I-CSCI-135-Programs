/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Checkerboard

Write a program checkerboard.cpp
that asks the user to input width 
and height and prints a rectangular 
checkerboard of the requested size 
using asterisks and spaces (alternating).
*/

#include <iostream>
using namespace std;
int main()
{
    int width, height;
    cout << "Input width ";
    cin >> width;
    cout << "Input height ";
    cin >> height;
    cout << "Shape: " << endl;
    for (int i=0; i < height; i++)
    {
        for (int j=0; j < width; j++)
        {
            if ((i+j)%2 == 0)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}