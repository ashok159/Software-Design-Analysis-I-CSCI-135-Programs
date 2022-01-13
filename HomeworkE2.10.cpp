//Name: Ashok Surujdeo
//CSCI 135
//Homework E.210

#include <iostream>
using namespace std;

int main()
{
    float gallons, fueleff, price;
    cout << "Enter the number of gallons: " << endl;
    cin >> gallons;
    cout << "Enter the fuel efficiency: " << endl;
    cin >> fueleff;
    cout << "Enter the price per gallon: " << endl;
    cin >> price;
    float cpm = (int(100)/fueleff)*price;
    float distance = gallons*fueleff;
    cout << "Cost per 100 miles: " << cpm << endl;
    cout << "Distance: " << distance << endl;
    return 0;
}