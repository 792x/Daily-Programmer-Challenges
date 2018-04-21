/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2901
 *
 * Created on April 21, 2018, 11:32 AM
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

/*
create a program that will ask the users name, age, and reddit username. have 
it tell them the information back, in the format:
your name is (blank), you are (blank) years old, and your username is (blank)
for extra credit, have the program log this information in a file to be 
accessed later.
 */

int forceCalculator(int m, int a){
    
    return m * a;
    
}

int main(int argc, char** argv) {
    
    int m;
    int a;
    
    cout << "What is the mass?" << endl;
    cin >> m;
    
    cout << "What is the accelleration?" << endl;
    cin >> a;
    
    cout << "The force is: " forceCalculator(m, a) << endl;

    return 0;
}

