//Name: Ashok Surujdeo
//CSCI 135
//Homework E4.8

#include <iostream>
using namespace std;
int main()
{
    string word;
    cout << "Enter a word: ";
    cin >> word;
    for (int i = 0; i < word.length(); i++)
        cout << word[i] << endl;
    return 0;
}