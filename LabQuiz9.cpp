//Name: Ashok Surujdeo
//CSCI 135
//Lab Quiz 9

#include <iostream>
#include <string>
using namespace std;

int unbalanced_brackets(string input)
{
    char c = '{';
    int ob = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == c)
            ob++;
        else
            ob--;
    }
    return ob;
}

int main()
{
    string s;
    cout << "Enter a string " << endl;
    cin >> s;
    cout << unbalanced_brackets(s) << endl;
    return 0;
}