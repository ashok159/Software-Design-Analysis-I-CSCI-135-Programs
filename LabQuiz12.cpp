//Name: Ashok Surujdeo
//CSCI 135
//Lab Quiz 12

#include <iostream>
#include <string>
using namespace std;

class Customer{
    private:
        string name;
        string unique_id;
    public:
        Customer();

        Customer(string name, string unique_id);
        string get_name();
        string get_unique_id();
        void set_name(string name);
        void set_unique_id(string uniqueid);
};

Customer::Customer(){}

Customer::Customer(string name, string unique_id): name(name), unique_id(unique_id){}

string Customer::get_name(){
    return name;
}

string Customer::get_unique_id(){
    return unique_id;
}

void Customer::set_name(string name){
    this->name = name;
}

void Customer::set_unique_id(string uniqueid){
    unique_id = uniqueid;
}

int main()
{
    Customer customer;
    customer.set_name("Bruce");
    customer.set_unique_id("10");

    cout << "Name: " << customer.get_name() << endl;
    cout << "Unique ID: " << customer.get_unique_id() << endl;
    return 0;
}