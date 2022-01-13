/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Fibonacci

This program uses an array of ints to compute and print all Fibonacci numbers from F(0) to F(59).
It will first create an array of 60 which is how many numbers will be printed.
It'll print the first two terms and then the rest of the terms iteratively.
*/

#include <iostream>
using namespace std;
int main()
{   
    int first = 0;
    int second = 1;
    int third;
    cout << first << endl;
    cout << second << endl;
    for (int i = 2; i < 60; i++)
    {
        third = first + second;
        cout << third << endl;
        first = second;
        second = third;
    }
    return 0;
}