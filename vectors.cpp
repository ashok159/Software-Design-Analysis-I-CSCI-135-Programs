/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Vectors

For this task, program a function 
called vector<int> makeVector(int n) 
that returns a vector of n integers 
that range from 0 to n-1. Call your 
program vectors.cpp.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n) {
    vector<int> result;
    for (int i = 0; i < n; i++) {
        result.push_back(i);
    }
    return result;
}
