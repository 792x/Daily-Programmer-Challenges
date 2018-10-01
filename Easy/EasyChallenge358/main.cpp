/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 792
 *
 * Created on April 24, 2018, 2:15 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/*
 * A program that deciphers a seven segment display, commonly seen on older 
 * electronic devices. Receives 3 lines of input, each being 27 chars long, 9 digits
 * spread across 3 lines. Returns the digits.
 * 
 * https://www.reddit.com/r/dailyprogrammer/comments/8eger3/20180423_challenge_358_easy_decipher_the_seven/
 */



string input1[3] = {"    _  _     _  _  _  _  _ ", "  | _| _||_||_ |_   ||_||_|", "  ||_  _|  | _||_|  ||_| _|"};
string input2[3] = {"    _  _  _  _  _  _  _  _ ", "|_| _| _||_|| ||_ |_| _||_ ", "  | _| _||_||_| _||_||_  _|"};
string input3[3] = {" _  _  _  _  _  _  _  _  _ ", "|_  _||_ |_| _|  ||_ | ||_|", " _||_ |_||_| _|  ||_||_||_|"};
string input4[3] = {" _  _        _  _  _  _  _ ", "|_||_ |_|  || ||_ |_ |_| _|", " _| _|  |  ||_| _| _| _||_ "};

void printDigits(string top, string middle, string bottom) {
    string temp1, temp2, temp3;
    vector<string> topblocks(0);
    vector<string> middleblocks(0);
    vector<string> bottomblocks(0);

    for (int i = 0; i < middle.length(); i+=3){
        temp1 = top.substr(i, 3);
        temp2 = middle.substr(i, 3);
        temp3 = bottom.substr(i, 3);
        topblocks.push_back(temp1);
        middleblocks.push_back(temp2);
        bottomblocks.push_back(temp3);
    }
    
    vector<int> results;

    for (vector<string>::size_type i = 0; i != middleblocks.size(); i++) {
        if(middleblocks[i] == "| |"){
            results.push_back(0);
        }
        if(middleblocks[i] == "  |"){ // 1 or 7
            if(topblocks[i] == " _ "){
                results.push_back(7);
            } else {
                results.push_back(1);
            }
            
        } else if(middleblocks[i] == " _|"){ //2 or 3
            if(bottomblocks[i] == "|_ "){
                results.push_back(2);
            } else {
                results.push_back(3);
            }
            
        } else if(middleblocks[i] == "|_|"){ //4, 8 or 9
            if(bottomblocks[i] == "  |"){
                results.push_back(4);
            } else if (bottomblocks[i] == "|_|"){
                results.push_back(8);
            } else{
                results.push_back(9);
            }
        } else if(middleblocks[i] == "|_ "){ //5 or 6
            if(bottomblocks[i] == " _|"){
                results.push_back(5);
            } else {
                results.push_back(6);
            }
            
        }
    }

    for (vector<int>::size_type i = 0; i != results.size(); i++) {
        cout << results[i];
    }
    cout << endl;
}

int main(int argc, char** argv) {
    printDigits(input1[0], input1[1], input1[2]);
    printDigits(input2[0], input2[1], input2[2]);
    printDigits(input3[0], input3[1], input3[2]);
    printDigits(input4[0], input4[1], input4[2]);
    return 0;
}

