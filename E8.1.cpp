//Name: Ashok Surujdeo
//CSCI 135
//Homework E8.1

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream file;
    file.open("hello.txt");
    file << "Hello, World!";
    file.close();

    ifstream in;
    in.open("hello.txt");

    string message;
    getline(in, message);

    cout << message << endl;
    in.close();
    return 0;
}