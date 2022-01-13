/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: East-Storage

This program will read in the dataset taken from the NYC Open Data website.
The data is filtered from the beginning of the year 2018 to the end of it.
It will ask the user to input a string representing the date in the form (MM/DD/YYYY).
Then it will print out the information about the East basin storage that day.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <cstring>

using namespace std;

int main()
{
    string date;
    double eastSt, eastEl, westSt, westEl;
    string datefromuser;
    cout <<"Enter: ";
    cin >> datefromuser;
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string junk; // new string variable
    getline(fin, junk);
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration
        fin.ignore(INT_MAX, '\n'); //skips to the end of line,
        //ignorring the remaining columns
        if(date==datefromuser){
            cout << "East basin storage: " << eastSt << " gallons" << endl;
        break;
        }
    }
    fin.close();
    return 0;
}