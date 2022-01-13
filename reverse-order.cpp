/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Reverse Order

This program will read in the dataset taken from the NYC Open Data website.
The data is filtered from the beginning of the year 2018 to the end of it.
Write a program reverse-order.cpp which asks the user to input two dates 
(earlier date then later date). The program should report the West basin elevation
for all days in the interval in the reverse chronological order 
(from the later date to the earlier).
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;
int main()
{
    string first, last;
    cout << "Enter earlier date: ";
    cin >> first;
    cout << "Enter later date: ";
    cin >> last;
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string junk;        // new string variable
    getline(fin, junk); // read one line from the file 
    string date;
    double eastSt, eastEl, westSt, westEl, minimum, maximum;
    string dates [400]; //creates dates variable and array
    double elevations [400]; // elevations variable
    int amount = 0;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        if (date >= first && date <= last)
        {
            dates[amount] = date;
            elevations[amount] = westEl;
            amount++;
        }
    }
    fin.close();
    for (int i = amount - 1; i >= 0; i--)
        cout << dates[i] << " " << elevations[i] << endl;
    return 0;
}
    