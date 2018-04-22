/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: css
 *
 * Created on April 22, 2018, 8:41 PM
 */

#include <cstdlib>

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

/*
 * Given a dollar amount between 0.00 and 999,999.00, create a program that will provide a worded representation of a dollar amount on a check.
 * 
 * https://www.reddit.com/r/dailyprogrammer/comments/6yep7x/20170906_challenge_330_intermediate_check_writer/
 */


vector<string> extra = {"thousand, ", "million, ", "billion, ", "trilion, ", "quadrillion, "};


string wordify(float input){
    
    string stringed = to_string(input);
    istringstream iss(stringed);
    vector<string> tokens;
    string token;
    while (getline(iss, token, '.')) {
        if (!token.empty()){
            tokens.push_back(token);
        }
    }
    
    string cents = tokens[1];
    
    if (tokens.size() < 2) {
        cents = "and zero cents.";
    } else if (stoi(tokens[1]) == 0) {
        cents = "and zero cents.";
    } else {
        cents = " and " + numbersToString(stoi(tokens[1].substr(0,2))) + "cents.";
    }

    string integers = numbersToString((int) (stod(tokens[0])) % 1000);

    int length = tokens[0].length();
    long original = (stod(tokens[0]));
    for (int i = 0; i < length - 3; i += 3) {
        long factor = (long) (1000 * pow(10, i));
        integers = numbersToString((int) (original / factor % 1000)) + extra[i / 3] + integers;
    }
    return (integers + "euro" + cents);
    
}

string numbersToString(int input) {

    switch (input) {
        case 0:
            return "";
        case 1:
            return "one ";
        case 2:
            return "two ";
        case 3:
            return "three ";
        case 4:
            return "four ";
        case 5:
            return "five ";
        case 6:
            return "six ";
        case 7:
            return "seven ";
        case 8:
            return "eight ";
        case 9:
            return "nine ";
        case 10:
            return "ten ";
        case 11:
            return "eleven ";
        case 12:
            return "twelve ";
        case 13:
            return "thirteen ";
        case 14:
            return "fourteen ";
        case 15:
            return "fifteen ";
        case 16:
            return "sixteen ";
        case 17:
            return "seventeen ";
        case 18:
            return "eighteen ";
        case 19:
            return "nineteen ";
        case 20:
            return "twenty ";
        case 30:
            return "thirty ";
        case 40:
            return "fourty ";
        case 50:
            return "fifty ";
        case 60:
            return "sixty ";
        case 70:
            return "seventy ";
        case 80:
            return "eighty ";
        case 90:
            return "ninety ";
        default:
            int hundreds = input % 1000 / 100;
            int decimals = input % 100 / 10;
            int integers = input % 10;

            string result = "";

            if (hundreds > 0) {
                result += numbersToString(hundreds) + "hundred ";
            }
            if (decimals > 1) {
                result += numbersToString(decimals * 10);
                if (integers > 0) {
                    result += numbersToString(integers);
                }
            } else if (decimals != 0) {
                result += numbersToString(decimals * 10 + integers);
            }

            return result;
    }
}
 
int main(int argc, char** argv) {
    
    float input;
    
    cout << "Input a number:" << endl;
    cin >> input;
    
    cout << wordify(input) << endl;
    

    return 0;
}

