/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Vigenere

Write a program vigenere.cpp. It should contain a function encryptVigenere.
You may assume that the keyword contains only lowercase alphabetic characters a - z.
The main should implement a testing interface similar to the one in Task B, the user 
enters the plaintext and the keyword, and the program reports the ciphertext.
*/

#include <iostream>
#include <string>
using namespace std;

int key(char a){                    //returns 0-25 for characters
    int t = (int)a;
    if(t >= 97 && t <= 122){
        return t - 97;
    }
    else return -1;
}

char fromkey(int x){                // returns character from 0-25
    x += 26;
    return (char)((x % 26)+97);
}

int myhash(string word){
    int static i = -1;
    i++;
    i %= word.length();
    return key(word[i]);
}

char shiftChar(char c, int rshift){
    char a = tolower(c);
    int n = ((int)a - 97 + rshift);
    n += 26;
    n =  n % 26;
    n += 97;
    a = (char)n;

    if((int)c >= 65 && (int)c <= 90){ // uppercase letters
        a = toupper(a);
        return a;
    }

    if((int)c >= 97 && (int)c <= 122){ // lowercase letters
        return a;
    }
    else{ //punctuation
        return c;
    }
}

string encryptVigenere(string plaintext, string keyword){
    string output;
    char tempchar;
    bool plainCASE = true; // if true, this is a lower case character
    for(int j=0; j<plaintext.length(); j++){
        tempchar = tolower(plaintext[j]);
        plainCASE = (plaintext[j] == tempchar);

        if((int)tempchar >= 97 && (int)tempchar <= 122){
            if(plainCASE){
                output += fromkey(myhash(keyword)+key(tempchar));            
            }
            else{
                output += toupper(fromkey(myhash(keyword)+key(tempchar)));
            }
        }
        else{
            output += plaintext[j];
        }
    }
    return output;
}


int main(){
    string input = "";
    string new_word;
    cout << "Enter Plaintext: ";
    getline(cin, input); 
    cout << "Enter codeword: ";
    cin >> new_word;
    cout << "Ciphertext     : " << encryptVigenere(input, new_word) << endl;
    return 0;
}

