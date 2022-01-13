//Name: Ashok Surujdeo
//CSCI 135
//Homework E5.15

#include <iostream>
using namespace std;

void sort3(int& a, int& b, int& c){
    if (a > b){
        int i = a;
        a = b;
        b = i;
    }
    if (a > c){
        int j = a;
        a = c;
        c = j;
    }
    if (b > c){
        int k = b;
        b = c;
        c = k;
    }
    return;
}
int main()
{
    cout << "Enter three integers: " << endl;
    int num1;
    int num2;
    int num3;
    cin >> num1 >> num2 >> num3;

    int out1 = num1;
    int out2 = num2;
    int out3 = num3;

    sort3(out1, out2, out3);

    cout << out1 << " " << out2 << " " << out3 << endl;
    return 0;
}