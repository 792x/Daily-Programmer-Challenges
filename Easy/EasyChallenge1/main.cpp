/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: css
 *
 * Created on April 21, 2018, 11:25 AM
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

/*
 * create a program that will ask the users name, age, and reddit username. have 
 * it tell them the information back, in the format:
 * your name is (blank), you are (blank) years old, and your username is (blank)
 * for extra credit, have the program log this information in a file to be 
 * accessed later.
 * https://www.reddit.com/r/dailyprogrammer/comments/pih8x/easy_challenge_1/
 */

int main(int argc, char** argv) {
    
    string name;
    string username;
    int age;
    
    cout << "What is your name?" << endl;
    cin >> name;
    cout << "What is your age?" << endl;
    cin >> age;
    cout << "What is your username?" << endl;
    cin >> username;
    
    cout << "your name is " << name << ", you are " << age << " years old, and your username is " << username << endl;
    
    return 0;
}

