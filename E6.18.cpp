//Name: Ashok Surujdeo
//CSCI 135
//Homework E6.18

#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b)
{
    a.reserve(a.size() + b.size());
    a.insert(a.end(), b.begin(), b.end());
    return a;
}
