//Name: Ashok Surujdeo
//CSCI 135
//Lab Quiz 13

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n);

int main() 
{
    vector<int> v = makeVector(10);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}

vector<int> makeVector(int n) {
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(i);
    }
    return v;
}
