//Name: Ashok Surujdeo
//CSCI 135
//Homework E3.5

#include <iostream>
using namespace std;
int main()
{
    int num1, num2, num3;
    cout << "Enter a number: ";
    cin >> num1;
    cout << "Enter a number: ";
    cin >> num2;
    cout << "Enter a number: ";
    cin >> num3;
    if (num2 > num1 && num3 > num2)
        cout << "increasing" << endl;
    if (num2 < num1 && num3 < num2)
        cout << "decreasing" << endl;
    else   
        cout << "neither" << endl;
    return 0;
}