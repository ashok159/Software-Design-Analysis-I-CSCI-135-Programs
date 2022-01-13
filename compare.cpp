/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Compare

This program will read in the dataset taken from the NYC Open Data website.
The data is filtered from the beginning of the year 2018 to the end of it.
It will ask the user to input two dates (the beginning and the end of the interval). 
The program should check each day in the interval and report which basin had higher 
elevation on that day by printing “East” or “West”, or print “Equal” if both basins 
are at the same level.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;
int main()
{
    string date;
    string first_date;
    string last_date;
    cout << "Enter starting date: ";
    cin >> first_date;
    cout << "Enter ending date: ";
    cin >> last_date;
    double eastSt, eastEl, westSt, westEl, minimum, maximum;
    int i = 0;
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string junk;        // new string variable
    getline(fin, junk); // read one line from the file 
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        if (date  >= first_date && date <= last_date)
        {
            if (eastEl > westEl)
                cout << date << " " << "East" << endl;
            else if (eastEl < westEl)
                cout << date << " " << "West" << endl;
            else
                cout << date << "Equal" << endl;
        }
        getline(fin,junk);
    }
    fin.close();
    return 0;
}
            
