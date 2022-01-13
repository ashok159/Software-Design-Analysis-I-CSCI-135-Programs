/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Fibonacci

Write a program caesar.cpp with functions implementing Caesar cipher encryption.
The main function should ask the user to input a plaintext sentence, 
then enter the right shift, and report the ciphertext computed using your encryption function.
*/

#include <iostream>
#include <string>
using namespace std;

char shiftChar(char c, int rshift)
{
    char t = tolower(c);
    int n = ((int)t - 97 + rshift);
    n += 26;
    n =  n % 26;
    n += 97;
    t = (char)n;

    if((int)c >= 65 && (int)c <= 90){ // uppercase letters
        t = toupper(t);
        return t;
    }

    if((int)c >= 97 && (int)c <= 122){ // lowercase letters
        return t;
    }
    else{ //punctuation
        return c;
    }
}
string encryptCaesar(string plaintext, int rshift)
{
    string result;
    for(int i=0; i < plaintext.length(); i++){
    result += shiftChar(plaintext[i], rshift);
    }
    return result;
}

int main()
{
    string plain;
    int shift;
    int i = 0;
    cout << "Enter plaintext: ";
    getline(cin, plain);
    cout << "Enter shift: ";
    cin >> shift;
    cout << "Ciphertext " << encryptCaesar(plain, shift) << endl;
    return 0;
}