/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2901
 *
 * Created on April 21, 2018, 11:37 AM
 */

#include <cstdlib>
#include <string>
#include <iostream>


using namespace std;

/*
 * create a program that will guess numbers between 1-100, and respond 
 * appropriately based on whether users say that the number is too high or too low
 * https://www.reddit.com/r/dailyprogrammer/comments/pii6j/difficult_challenge_1/
 */

int main(int argc, char** argv) {
    
    int max = 100;
    int min = 1;
    string input;
    bool guessed = false;
    
    while (!guessed){
        
        int guess = (max + min)/2;
        
        cout << "My guess is: " << guess << ", is it (c)orrect, (h)igher or (l)ower?" << endl;
        cin >> input;
        
        if(input == "c"){
            
            cout << "I guessed it, your number was: " << guess << endl;
            guessed = true;
            
        } else if(input == "h"){
            
            min = guess;
            
        } else if(input == "l"){
            
            max = guess;
            
        } else {
            
            cout << "Is it (c)orrect, (h)igher or (l)ower?" << endl;
            
        }
    }
    
    
    return 0;
}

