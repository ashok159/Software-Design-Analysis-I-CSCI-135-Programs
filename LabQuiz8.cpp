//Name: Ashok Surujdeo
//CSCI 135
//Lab Quiz 8

#include <iostream>
#include <string>
using namespace std;

class Date {
    public:
        int day;
        int year;
        int month;
        string day_of_week;
};

void printDate(Date *input) {
    cout << input->day_of_week << ", " << input->month << "/" << input->day << "/" << input->year << endl;
}

int main()
{
    Date date1;
    date1.month = 12;
    date1.day = 6;
    date1.year = 2021;
    date1.day_of_week = "Monday";

    printDate(&date1);
    return 0;
}