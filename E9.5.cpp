//Name: Ashok Surujdeo
//CSCI 135
//Homework E9.5

#include <iostream>
using namespace std;

class Rectangle
{
private:
    double width;
    double height;
public:
    Rectangle(double w, double h)
    {
        width = w;
        height = h;
    }
    double get_perimeter()
    {
        return 2*(width+height);
    }
    double get_area()
    {
        return width*height;
    }
    void resize(double factor)
    {
        width = width*factor;
        height = height*factor;
    }
};

int main()
{
    Rectangle rect(10, 20);
    cout << "Perimeter of Rectangle :" << rect.get_perimeter () << endl;
    cout << "Area of Rectangle : " << rect.get_area () << endl;
    rect.resize (2);
    cout << "After resizing with factor 2 :" << endl;
    cout<<"Perimeter of Rectangle :"<<rect.get_perimeter()<<endl;
    cout<<"Area of Rectangle : "<<rect.get_area()<<endl;

    return 0;
}