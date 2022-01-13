/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1D

Write an even better calculator program calc3.cpp 
that can understand squared numbers. 
We are going to use a simplified notation X^ to mean X2. 
For example, 10^ + 7 - 51^ should mean 102 + 7 − 512.
*/

#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int next;
    char op;
    cin >> sum;
    if (cin.peek() == '^')
    {
        sum = sum * sum;
        cin.ignore();
    }
    while (cin >> op >> next)
    {
        if (cin.peek() == '^')
        {
            next = next * next;
            cin.ignore();
        }
        if (op == ';')
        {
            cout << sum << endl;
            sum  = next;
        }
        else if (op == '+')
            sum = sum + next;
        else if (op == '-')
            sum = sum - next;
    }
    cout << sum << endl;
    return 0;
}