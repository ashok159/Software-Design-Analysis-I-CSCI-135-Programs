/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Optimism

Make a program called optimism.cpp 
that implements the function vector<int> 
goodVibes(const & vector<int> v); that, 
given a vector of integers, returns a 
vector with only the positive integers in the same order.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(vector<int> v) {
  vector<int> result;
  vector<int> negatives;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] > 0) {
      result.push_back(v[i]);
    }
    else if (v[i] < 0) {
      negatives.push_back(v[i]);
    }
  }
  return result;
}
