//Name: Ashok Surujdeo
//CSCI 135
//Homework E6.8

#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size){
    bool num = true;
    
    if (a_size != b_size)
        return false;

    for(int i = 0; i < a_size; i++){
        if(a[i] != b[i])
            num = false;       
    }
    return num;
}

int main()
{   
    int a_size,b_size;
    cin>>a_size;
    b_size = a_size;
    int a[a_size],b[b_size];
    for(int i =0; i<a_size;i++)
    {        
        cin>>a[i];   
    }
    for(int i =0; i<a_size;i++)
    {        
        cin>>b[i];    
    }
    cout << equals(a,a_size, b, b_size);
    return 0;
}