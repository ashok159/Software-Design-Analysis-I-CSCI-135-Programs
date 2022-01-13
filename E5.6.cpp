//Name: Ashok Surujdeo
//CSCI 135
//Homework E5.6

#include <iostream>
using namespace std;

string middle(string word)
{
    int pos = word.length() / 2;
    if (word.length() % 2 == 0)
    {
        word = word.substr(pos - 1, 2);
    }
    else
    {
        word = word[pos];
    }
    return word;
}
int main()
{
    string word;
    cout << "Enter a word: ";
    cin >> word;
    string mid = middle(word);
    cout << mid << endl;
    return 0;
}