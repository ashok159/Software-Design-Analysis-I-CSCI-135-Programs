/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Checkerboard 3x3

Write a program checkerboard3x3.cpp
that asks the user to input width 
and height and prints a checkerboard 
of 3-by-3 squares. (It should work 
even if the input dimensions are 
not a multiple of three.)
*/

#include <iostream>
using namespace std;

int main()
{
    int width, height;
    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;
    char row_begin = '*';
    char d = '*';
    cout << endl;
    for(int row = 1; row <= height; row++)  //rows
    {
        d = row_begin; //start with the character that the row should begin with
        for(int col = 1; col <= width; col++)  //columns
        {
            cout << d;
            if(col % 3 == 0)  //skips 3 columns
            {
                if(d == '*')
                d = ' '; 
                else
                d = '*';
            }
        }
        cout << endl;
        if(row % 3 == 0)  //skips 3 rows
        {
            if(row_begin == '*')
            row_begin = ' ';
            else
            row_begin = '*';
        }
    }
    return 0;
}