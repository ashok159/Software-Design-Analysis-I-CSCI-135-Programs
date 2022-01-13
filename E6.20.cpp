//Name: Ashok Surujdeo
//CSCI 135
//Homework E6.20

#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_sorted(vector<int> a, vector<int> b)
{
    int s1,s2,i=0,j=0;
    vector<int> merged;
    s1 = a.size();
    s2 = b.size();
    while(i<s1 && j<s2){
        if(a[i]<b[j]){
            merged.push_back(a[i]);
            i++;
        }
        else{
            merged.push_back(b[j]);
            j++;
        }
    }
    while(i<s1){
        merged.push_back(a[i]);
        i++;
    }
    while(j<s2){
        merged.push_back(b[j]);
        j++;
    }
    return merged;
}