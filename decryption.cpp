/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Decryption

Write a program decryption.cpp that 
uses the above functions to demonstrate 
encryption and decryption for both ciphers.
*/

#include <iostream>
#include <string>
using namespace std;

//global index for Vigenere cipher
int vigenereIndex = -1;

int key(char a){                    //returns 0-25 for characters
    int temp = (int)a;
    if(temp >= 97 && temp <= 122){
        return temp - 97;
    }
    else return -1;
}
char fromkey(int x){                // returns character from 0-25
    x += 26;
    return (char)((x % 26)+97);
}

int myhash(string word){
    vigenereIndex++;
    vigenereIndex%=word.length();
    return key(word[vigenereIndex]);
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

string encryptCaesar(string plaintext, int rshift){
    string output;
    for(int i=0; i < plaintext.length(); i++){
    output += shiftChar(plaintext[i], rshift);
    }
    return output;
}

string encryptVigenere(string plaintext, string keyword){
    string output;
    char tempchar;
    bool plainCASE = true; // if true, this is a lower case character
    vigenereIndex = -1; // reset for this Vigenere run
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

string decryptCaesar(string ciphertext, int rshift){    //negates caesar shift
    return encryptCaesar(ciphertext, 0-rshift);
}

string decryptVigenere(string ciphertext, string keyword){ //Reverse implementation of Vigenere Cipher
    string output;
    char tempchar;
    bool plainCASE = true; // if true, this is a lower case character
    vigenereIndex = -1; // reset for this Vigenere run
    for(int j=0; j<ciphertext.length(); j++){
        // cout << ciphertext[j] << endl;
        tempchar = tolower(ciphertext[j]);
        plainCASE = (ciphertext[j] == tempchar);

        if((int)tempchar >= 97 && (int)tempchar <= 122){
            if(plainCASE){
                output += fromkey(key(tempchar)-myhash(keyword));            
            }
            else{
                output += toupper(fromkey(key(tempchar)-myhash(keyword)));
            }
        }
        else output += ciphertext[j];
    }
    return output;
}


int main(){
    string input = "";
    int shift;
    string new_word;
    cout << "Enter Plaintext: ";
    getline(cin, input);
    cout << "= Caesar =\n Enter Shift    : ";
    cin >> shift;
    string caesarText = encryptCaesar(input, shift);
    cout << "Ciphertext     : " << caesarText << endl;
    cout << "Decrypted      : " << decryptCaesar(caesarText, shift) << endl << endl;

    cout << "= Vigenere = \n Enter keyword  : ";
    cin >> new_word;
    string vigenereText = encryptVigenere(input, new_word);
    cout << "Ciphertext     : " << vigenereText << endl;
    cout << "Decrypted      : " << decryptVigenere(vigenereText, new_word) << endl;
    
    
    return 0;
}