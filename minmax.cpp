/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Min-Max

This program will read in the dataset taken from the NYC Open Data website.
The data is filtered from the beginning of the year 2018 to the end of it.
It will read the file line by line and keep track of what is the highest and lowest storage level in the basin so far.
After reading the file entirely, it will print the minimum and maximum values.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;
int main()
{
    string date;
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
    
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                          //ignorring the remaining columns 

        if(i == 0) 
        {
            minimum = eastSt;
            maximum = eastSt;
        }
        if (minimum > eastSt)
            minimum = eastSt;
        if (maximum < eastSt)
            maximum = eastSt;
        i++;
    }

    cout << "minimum storage in East basin: " << minimum << endl;
    cout << "Maximum storage in East basin: " << maximum << endl;
    fin.close();
    return 0;
}