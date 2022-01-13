//Name: Ashok Surujdeo
//CSCI 135
//Homework E7.1

#include <iostream>
using namespace std;

void sort2(double* p, double* q)
{
    
    if (*p < *q)
        return;
    else
    {
        *p = *p + *q;
        *q = *p - *q;
        *p = *p - *q;
    }
    return;
}

int main()
{
    double x = 0;
    double y = 0;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    sort2(&x, &y);
    cout << x << " " << y;
    return 0;
}