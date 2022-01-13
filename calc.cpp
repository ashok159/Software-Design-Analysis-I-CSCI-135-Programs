/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1B

This program uses reads from the cin a sequence of one or more non negative integers.
These integers are to be added or subtracted based on the mathematical symbol given.
Space characters can be anywhere in the input and after the input ends, the program
will compute and print the result.
*/ 

#include <iostream>
using namespace std;

int main() {
    char op;
    int sum = 0;
    int value;

    cin >> sum;

    while(cin >> op >> value) {
        if(op == '+') {
            sum += value;
        }
        else if(op == '-') {
            sum -= value;
        }
    }
    cout << sum << endl;
}
