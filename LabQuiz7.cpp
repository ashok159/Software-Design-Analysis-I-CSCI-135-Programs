//Name: Ashok Surujdeo
//CSCI 135
//Lab Quiz 7

#include <iostream>
#include <algorithm>
using namespace std;

void remove_e(string & sentence)
{
    sentence.erase(remove(sentence.begin(), sentence.end(), 'e'), sentence.end());
}