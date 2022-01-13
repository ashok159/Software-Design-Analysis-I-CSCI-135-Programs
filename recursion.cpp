/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Recursion

Write a program recursion.cpp, defining a function
void printRange(int left, int right);
that prints all numbers in range left ≤   x   ≤ right, 
separated by spaces. (Don’t use loops, global or static variables.)
In the same program, add a new function
which returns true if all characters in the string are letters
and digits, otherwise returns false.
*/

#include <iostream>
#include <cmath>
using namespace std;


void printRange(int left, int right){
  if (right + 1 > left) {
    std::cout << left << " ";

    printRange(left + 1, right);
  }
  else if (left > right) {
    return;
  }
}

int sumRange(int left, int right)
{
  int sum;

  if (right < left) { 
    return 0; 
  }

  else
  {
    sum = left + sumRange(left + 1, right);
  }

  return sum;
}

int sumArrayInRange(int *arr, int left, int right)
{
  int sum;

  if (right < left) { 
    return 0; 
  }

  else
  {
    sum = arr[left] + sumArrayInRange(arr, left + 1, right);
  }

  return sum;

}

int sumArray(int *arr, int size)
{
  return sumArrayInRange(arr, 0, size-1);
}

bool isAlphanumeric(string s)
{
  if (s.length() == 0){
    return true;
  }

  else if (!isalpha(s[0]) & !isdigit(s[0])) {
    return false;
  }

  else { 
    return isAlphanumeric(s.substr(1, s.length() - 1)); 
  }
}

bool nestedParens(string s)
{
  if (s.length() == 0) {
    return true;
  }
  
  if ((s.length() % 2) != 0) {
    return false;
  }

  if (!(s[0] == '(' && s[s.length() - 1] == ')')) {
    return false;
  }

  else {
    return nestedParens(s.substr(1, s.length() - 2));
  }
}


