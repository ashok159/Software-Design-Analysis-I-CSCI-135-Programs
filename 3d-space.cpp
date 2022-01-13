/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: 3-D Space

Write a program 3d-space.cpp, 
in which you define a function length() 
that receives the coordinates of a point 
P passed as a pointer, and computes the 
distance from the origin to the point P.
*/

#include <iostream>
#include <math.h>
using namespace std;

class Coord3D {
public:
    double x;
    double y;
    double z;
};

double length(Coord3D* p){
    double len = sqrt(pow(p->x,2) + pow(p->y,2) + pow(p->z,2));
    return len;
}

Coord3D* fartherFromOrigin(Coord3D* p1, Coord3D* p2){
    if ( ( (p1->x * p1->x) + (p1->y * p1->y) + (p1->z * p1->z) ) > ( (p2->x * p2->x) + (p2->y * p2->y) + (p2->z * p2->z) ) )
    {
        return p1;
    }
    else
    {
        return p2;
    }
}

void move(Coord3D* ppos, Coord3D* pvel, double dt){
    Coord3D &v = *ppos;
    Coord3D &X = *pvel;
    v.x = v.x + (X.x*dt);
    v.y = v.y + (X.y*dt);
    v.z = v.z + (X.z*dt);
    *ppos = v;
}

Coord3D* createCoord3D(double x, double y, double z){
    Coord3D* ppos = new Coord3D;
    ppos->x = x;
    ppos->y = y;
    ppos->z = z;
    return ppos;
}

void deleteCoord3D(Coord3D* p){
    delete p;
}

int main(){
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
}