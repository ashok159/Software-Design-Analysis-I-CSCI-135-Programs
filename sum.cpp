/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project1A

This program asks the user to input the name of a txt file.
Then it will read a sequence of integers using cin from that txt file and prints their sum.
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a sequence of integers: ";
    int sum=0;
    int number;
    while (cin >> number)
        sum = sum+number;
    cout << sum << endl;
    return 0;
}