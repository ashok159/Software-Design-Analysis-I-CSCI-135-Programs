//Name: Ashok Surujdeo
//CSCI 135
//Homework E9.3

#include <iostream>
using namespace std;

class Circuit
{
    int switch1;
    int switch2;
    int lamp;
    public:
    Circuit(){
        switch1=0;
        switch2=0;
        lamp=0;
    }
    int get_first_switch_state()
    {
        return switch1;
    }
    int get_second_switch_state()
    {
        return switch2;
    }
    int get_lamp_state()
    {
        return lamp;
    }
    void toggle_first_switch()
    {
        switch1 = (switch1==1?0:1);
        lamp = (lamp==1?0:1);
    }
    void toggle_second_switch()
    {
        switch2 = (switch2==1?0:1);
        lamp = (lamp==1?0:1);
    }
};

