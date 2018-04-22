/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: css
 *
 * Created on April 21, 2018, 11:32 AM
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

/*
 * create a calculator application that has use in your life. 
 * It might be an interest calculator, or it might be something that you can 
 * use in the classroom. For example, if you were in physics class, you might 
 * want to make a F = M * A calc.
 * https://www.reddit.com/r/dailyprogrammer/comments/pjbj8/easy_challenge_2/
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

