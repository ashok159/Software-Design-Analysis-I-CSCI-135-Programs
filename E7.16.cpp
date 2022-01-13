//Name: Ashok Surujdeo
//CSCI 135
//Homework E7.16

#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    double x;
    double y;
};

double distance(Point a, Point b)
{
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}

int main()
{
    Point p1, p2;
    cout << "Enter coordinates for point 1: ";
    cin>>p1.x>>p1.y;
    cout << "Point 2: ";
    cin>>p2.x>>p2.y;
    cout << distance(p1, p2);
    return 0;
}