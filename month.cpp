/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab1A

This program asks the user to input the year and the month.
Then it will print the number of days within that given month taking into account whether it is a leap year or not.
If it is a leap year then February will have 28 days.
If it is a common year then February will have 29 days.
Multiple if statements are contained within the month of February due to the many factors that contribute to a leap or common year.
*/

#include <iostream>
using namespace std;

int main()
{
    int year, month;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter month: ";
    cin >> month;
    if (month == 1)
        cout << "31 days" << endl;
    if (month == 2)
    {
        if (year%100 == 0)
        {
            if (year%400 == 0)
                cout << "29 days" << endl;
            else 
                cout << "28 days" << endl;
        }
        else if (year%100 != 0)
        {
            if (year%4 == 0)
                cout << "29 days" << endl;
            else 
                cout << "28 days" << endl;
        }
    }
    if (month == 3)
        cout << "31 days" << endl;
    if (month == 4)
        cout << "30 days" << endl;
    if (month ==5)
        cout << "31 days" << endl;
    if (month == 6)
        cout << "30 days" << endl;
    if (month == 7)
        cout << "31 days" << endl;
    if (month == 8)
        cout << "31 days" << endl;
    if (month == 9)
        cout << "30 days" << endl;
    if (month == 10)
        cout << "31 days" << endl;
    if (month == 11)
        cout << "30 days" << endl;
    if (month == 12)
        cout << "31 days" << endl;
    return 0;
}