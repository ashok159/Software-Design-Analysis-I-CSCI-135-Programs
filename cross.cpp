/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yee
Assignment: Cross

Write a program cross.cpp
that asks the user to input
the shape size, and prints
a diagonal cross of that dimension.
*/

#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    cout << endl;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if ((j == i) || (j == (size + 1 - i)))
                cout << "*";
            else 
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}