/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2901
 *
 * Created on April 21, 2018, 11:25 AM
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

/*
 create a calculator application that has use in your life. 
 * It might be an interest calculator, or it might be something that you can 
 * use in the classroom. For example, if you were in physics class, you might 
 * want to make a F = M * A calc.
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

