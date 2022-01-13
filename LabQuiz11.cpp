////Name: Ashok Surujdeo
//CSCI 135
//Lab Quiz 11

#include <iostream>
using namespace std;

class Money{
    public:
        int dollars;
        int cents;
};

Money add_money(Money x, Money y)
{
    Money sum;
    sum.dollars = x.dollars + y.dollars;
    sum.cents = x.cents + y.cents;

    if(sum.cents>=100){
        sum.dollars+= (sum.cents)/100; 
        sum.cents = sum.cents%100; 
    }

    return sum;
}
