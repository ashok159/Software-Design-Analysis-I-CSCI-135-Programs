//Name: Ashok Surujdeo
// CSCI 135
//Lab Quiz 4

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in_file;
    in_file.open("data.txt");
    string str;
    while(!in_file.eof()){ 
		in_file >> str; 
		cout<< str <<endl; 
    }
    in_file.close();
    return 0;
}