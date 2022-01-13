/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Indent

Write a new program indent.cpp that 
enhances the program from the previous task. 
As it reads the input line by line, it should 
also count the number of open and closed { } in 
it, and keep track of how many blocks is currently 
open at the beginning of each line.
*/

#include <iostream>
#include <cctype>
using namespace std;

string removeLeadingSpaces(string line)
{
    int i = 0;
    while (isspace(line[i]))
        i++;
        
    return line.substr(i);
}

int countChar(string line, char c)
{
    int count = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == c)
            count ++;
    }
    return count;
}

void printLine(string line, int indent)
{
    for (int i = 0; i < indent; i++)
        cout << '\t';

    cout << line << endl;
}

int main()
{
    string line;
    int openblocks = 0;
    while (getline(cin, line))
    {
        line = removeLeadingSpaces(line);

        if (line[0] == '}')
            printLine(line, openblocks-1);
        else
            printLine(line, openblocks);

        openblocks += countChar(line, '{') - countChar(line, '}');
    }
    return 0;
}