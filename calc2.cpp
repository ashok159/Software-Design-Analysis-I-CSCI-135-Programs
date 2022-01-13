/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1C

Write a better version of the calculator, calc2.cpp, 
that can evaluate multiple arithmetic expressions. 
Let’s use the semicolon symbol that must be used at 
the end of each expression in the input.
*/

#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int next;
    char op;
    cin >> sum;
    while (cin >> op >> next)
    {
        if (op == '+')
            sum = sum + next;
        if (op == '-')
            sum = sum - next;
        if (op == ';')
        {
            cout << sum << endl;
            sum =  next;
        }      
    }
    cout << sum << endl;
    return 0;
}