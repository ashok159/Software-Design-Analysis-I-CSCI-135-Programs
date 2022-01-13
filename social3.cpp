/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Social 3

Write a program social2.cpp, 
implementing the first version 
of the class Network. Write a new 
program social3.cpp, which is an 
improved version of the previous program.
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
    static const int MAX_USERS = 20; 
    int numUsers;                    
    Profile profiles[MAX_USERS];     
    bool following[MAX_USERS][MAX_USERS];    // new 
    int findID (string usrn);
public:
    Network();
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2); // new
    void printDot();                         // new
};

int Network::findID(string usrn)
{
    for(int i=0; i<numUsers; i++)
        if(profiles[i].getUsername() == usrn)
        {
            return i;
        }
    return -1;
}

Network::Network() : numUsers(0){
    for (int i = 0; i < MAX_USERS; i++){
        for (int j = 0; j < MAX_USERS; j++){
            following[i][j] = false;
        }
    }
}

bool Network::addUser(string usrn, string dspn){
    if(numUsers == MAX_USERS) return false;
    if(usrn.empty()) return false;
    for (char& x : usrn){
        if (!isalnum(x)) return false;
    }
    for(Profile& x : profiles){
        if (x.getUsername() == usrn) return false;
    }
    profiles[numUsers] = Profile(usrn, dspn);
    numUsers++;
    return true;
}

bool Network::follow(string usrn1, string usrn2)
{
    if (findID(usrn1) == -1)
        return false;
    else
    {
        for (int i=0; i < numUsers; i++)
            if(profiles[i].getUsername() == usrn2)
            {
                following[findID(usrn1)][i] = true;
                return true;
            }
    }
    return false;
}

void Network::printDot()
{
    cout << "digraph { "<< endl;
    for (int i=0; i < numUsers; i++)
    {
        cout << "  \"@" << profiles[i].getUsername() << "\"" << endl;
    }
        for (int i=0; i < numUsers; i++)
        {
            for(int j = 0; j < numUsers; j++)
            {
                if (following[i][j] == true)
                    cout <<  "  \"@" << profiles[i].getUsername() << "\"" " -> " << "\"@" << profiles[j].getUsername() << "\"" << endl;
            }
        }
    cout << "}" << endl;
}

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}