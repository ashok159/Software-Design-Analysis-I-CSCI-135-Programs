//Name: Ashok Surujdeo
//CSCI 135
//Lab Quiz 6

#include <iostream>
using namespace std;

int max3(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    if (b > a && b > c)
        return b;
    if (c > a && c > b)
        return c;
}
int main()
{
    int a;
    int b;
    int c;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    cout << max3(a, b, c) << endl;
    return 0;
}