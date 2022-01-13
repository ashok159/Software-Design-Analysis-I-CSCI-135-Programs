//Name: Ashok Surujdeo
//CSCI 135
//Homework E7.18

#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    double x;
    double y;
};

struct Triangle
{
    Point a;
    Point b;
    Point c;
};

double distance(Point x, Point y)
{
    return sqrt(pow(x.x-y.x,2) + pow(x.y-y.y,2));
}

double perimeter(Triangle triangle)
{
    return distance(triangle.a, triangle.b) + distance(triangle.b, triangle.c) + distance(triangle.a, triangle.c);   
}

int main()
{
    Point p1, p2, p3;
    cout << "Enter point 1: ";
    cin>>p1.x>>p1.y;
    cout << "Point 2: ";
    cin>>p2.x>>p2.y;
    cout << "Point 3: ";
    cin>>p3.x>>p3.y;

    Triangle triangle;
    triangle.a = p1;
    triangle.b = p2;
    triangle.c = p3;
    
    cout << perimeter(triangle) << endl;
    return 0;
}