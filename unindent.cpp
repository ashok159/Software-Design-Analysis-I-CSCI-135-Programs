/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Unindent

Write a program unindent.cpp 
that reads input from cin and 
prints out each input line with 
leading spaces removed.
*/

#include <iostream>
using namespace std;

string removeLeadingSpaces(string line)
{
    string result = "";
    bool check = true;
    for (int i = 0; i < line.size(); i++)
    {
        if (!(check && isspace(line[i])))
        {
            result += line[i];
            check = false;
        }
    }
    return result;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        cout << removeLeadingSpaces(line) << endl;
    }
    return 0;
}
