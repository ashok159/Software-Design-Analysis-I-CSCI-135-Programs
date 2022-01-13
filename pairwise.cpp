/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Pairwise

Write a program called pairwise.cpp 
that implements the function vector<int> sumPairWise(const vector<int> &v1, 
const vector<int> &v2) that returns a vector of 
integers whose elements are the pairwise sum of the 
elements from the two vectors passed as arguments. 
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2){
  vector<int> sum;
  if (v1.size() > v2.size()) {
    for (int i = 0; i < v2.size(); i++) {
      sum.push_back(v1[i] +v2[i]);
    }
    for (int i = v2.size(); i < v1.size(); i++) {
      sum.push_back(v1[i]);
    }
  }
  else if (v2.size() > v1.size()){
    for (int i = 0; i < v1.size(); i++) {
      sum.push_back(v1[i] +v2[i]);
    }
    for (int i = v1.size(); i < v2.size(); i++) {
      sum.push_back(v2[i]);
    }
  }
  else if(v1.size() == v2.size()) {
    for (int i = 0; i < v1.size(); i++){
      sum.push_back(v1[i] + v2[i]);
    }
  }
  return sum;
}

