/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Trapezoid

Write a program trapezoid.cpp 
that prints an upside-down 
trapezoid of given width and height.
However, if the input height is 
impossibly large for the given width,
then the program should report, 
Impossible shape!
*/

#include <iostream>
using namespace std;

int main()
{
    int width, height, spaces, i, j, b; //declare variables
    cout << "Enter width: "; //user input width
    cin >> width;
    cout << "Enter height: ";  //user input height
    cin >> height;
    cout << endl;  //prints shape on new line
    if (width % 2 == 0 && height > width / 2)  //width divided by a number divisbile by 2, each new line has 2 less *
    {
        cout << "Impossible shape!";
    }
    else if (width % 2 != 0 && height > (width / 2 + 1))  //not divisble by 2
    {
        cout << "Impossible shape!";  //otherwise print "Impossible shape!"
    }
    else
    {
        spaces = 0;
        for (i = 1; i <= height; i++)  //height increases by 1
        {
            for (b = 0; b < spaces; b++)  //loop to print spaces
                cout << " ";

            for (j = i; j <= width; j++)  //prints *
                cout << "*";

            cout << endl;  //each row prints on a new line

            width = width - 1;  //minus 1 made it more centered

            spaces++;  //increases space by 1
        }
    }
    return 0;
}