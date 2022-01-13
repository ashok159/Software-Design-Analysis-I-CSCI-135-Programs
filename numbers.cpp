/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Numbers

In the same program numbers.cpp, add a function
bool isPrime(int n);
The function should return true if n is a prime, 
otherwise return false. Change the main function
to test your new code.
Add a function that returns the number of prime 
numbers in the interval a ≤ x ≤ b. Change the
main function to test the new code.
Add a function
int nextTwinPrime(int n);
that returns the smallest twin prime greater than n.
*/

#include <iostream>
using namespace std;

bool isDivisibleBy(int n, int d){;
    if (d == 0)
        return false;
    else if (n % d == 0)
        return true;
    else    
        return false;
}

bool isPrime(int n){;
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int nextPrime(int n){;
    if (n <= 1)
        return 2;
    int prime = n;
    bool num = false;
    while (!num) {
        prime++;

        if (isPrime(prime))
            num = true;
    }
    return prime;
}

int countPrimes(int a, int b){;
    int primenum = 0;
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i))
            primenum++;
    }
    return primenum;
}

bool isTwinPrime(int n){;
    if(!isPrime(n))
        return false;
    if(isPrime(n-2) || isPrime(n+2))
        return true;
    else
        return false;
}

int nextTwinPrime(int n){;
    int i = n + 1;

    while(!(isTwinPrime(i)))
    {
        i++;
    }
    return i;
}

int largestTwinPrime(int a, int b){;
    for (int i = b; i >= a; i--)
    {
        if (isTwinPrime(i))
            return i;
    }
    return -1;
}

int main()
{
    int n, d;
    bool num;
    cout << "Enter first number: ";
    cin >> n;
    cout << "Enter second number: ";
    cin >> d;
    if (isDivisibleBy(n, d))
        cout << "Yes" << endl;
    else   
        cout << "No" << endl;
    
    if (isPrime(n))
        cout << n << "is a prime number" << endl;
    else 
        cout << n << "is not a prime number" << endl;

    cout << nextPrime(n) << endl;

    cout << countPrimes(n,d);
    
    num = isTwinPrime(n);
    if (num == true)
        cout << n << " is a twin prime";
    else    
        cout << n << " is not a twin prime";

    cout << nextTwinPrime(n);
    cout << largestTwinPrime(n,d);
    
    return 0;

}
