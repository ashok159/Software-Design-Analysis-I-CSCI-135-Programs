//Name: Ashok Surujdeo
//CSCI 135
//Homework E3.1

#include <iostream>
using namespace std;
int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    if (number == 0)
        cout << "zero" << endl;
    if (number < 0)
        cout << "negative" << endl;
    if (number > 0)
        cout << "positive" << endl;
    return 0;
}
