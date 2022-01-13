/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab1B

Write a program test-ascii.cpp 
that asks the user to input a line 
of text (which may possibly include spaces). 
The program should report all characters 
from the input line together with their ASCII codes.
*/

#include <iostream>
using namespace std;

int main()
{
    string s;
    cout << "Input: ";
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
        cout << s[i] << " " << (int)s[i] << endl;
    return 0;
}