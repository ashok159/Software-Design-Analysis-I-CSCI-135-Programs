/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Social 2

Write a program social2.cpp, 
implementing the first version 
of the class Network (feel free 
to copy your class Profile and 
anything else from the previous program).
*/

#include <iostream>
#include <string>
using namespace std;


class Profile{
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn);
    // Default Profile constructor (username="", displayname="")
    Profile();
    // Return username
    string getUsername();
    // Return name in the format: "displayname (@username)"
    string getFullName();
    // Change display name
    void setDisplayName(string dspn);
};

Profile::Profile(string usrn,string dspn)
{
    username = usrn;
    displayname = dspn;
}

Profile::Profile()
{
    username = "";
    displayname ="";
}

string Profile::getUsername()
{
    return username;
}

string Profile::getFullName()
{
    return displayname+" (@"+username+")";
}

void Profile::setDisplayName(string dspn)
{
    displayname = dspn;
}

class Network {
private:
    static const int MAX_USERS = 20; // max number of user profiles
    int numUsers;                      // number of registered users          
    Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

    // Returns user ID (index in the 'profiles' array) by their username
    // (or -1 if username is not found)
    int findID (string usrn);
public:
    // Constructor, makes an empty network (numUsers = 0)
    Network();
    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn);
};

Network::Network()
{
    numUsers = 0;
}

int Network::findID(string usrn)
{
    for(int i=0; i<numUsers; i++)
        if(profiles[i].getUsername() == usrn)
        {
            return i;
        }
    return -1;
}

bool Network::addUser(string usrn, string dspn)
{
    if (numUsers == MAX_USERS)
            return false;

    for (int i=0; i<numUsers; i++)
    {
        if (profiles[i].getUsername() == usrn)
            return false;
    }

    for (int i=0; i<usrn.length(); i++)
    {
        if (!isalpha(usrn[i]) && !isdigit(usrn[i]))
        {
            return false;
        }
    }
    profiles[numUsers] = Profile(usrn, dspn);
    numUsers++;
    return true;
    // After checking everyhting and there is no 'false', now we can add a new user

}

int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}




