/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: css
 *
 * Created on April 22, 2018, 5:32 PM
 */

#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <cstring>


using namespace std;

/*
 * 
 * A program that applies Goldbach's weak conjecture to numbers and shows which 3 primes, added together, yield the result.
 * 
 * \FORALL(n in natural numbers ; (\EXISTS(a,b,c in prime numbers ; n = a+b+c))
 * 
 * https://www.reddit.com/r/dailyprogrammer/comments/8bh8dh/20180411_challenge_356_intermediate_goldbachs/
 */

vector<int> primes(0);


void genPrimes(int n){
    // Sieve of Eratosthenes
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (prime[p])
           primes.push_back(p);
}


//O(n^3) lmao terrible complexity but whatever
int primeSum(int input) {
    for (vector<int>::size_type i = 0; i != primes.size(); i++) {
        for (vector<int>::size_type j = 0; j != primes.size(); j++) {
            for (vector<int>::size_type k = 0; k != primes.size(); k++) {
                if (input == (primes[i] + primes[j] + primes[k])) {
                    cout << primes[i] << "+" << primes[j] << "+" << primes[k] << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    int input;

    cout << "Input a number:" << endl;
    cin >> input;

    genPrimes(input);
    primeSum(input);

    return 0;
}

