/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 792
 *
 * Created on April 21, 2018, 12:13 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>


using namespace std;

/*
 * create a stopwatch program. this program should have start, stop, and lap options, and it should write out to a file to be viewed later.
 * https://www.reddit.com/r/dailyprogrammer/comments/pjsdx/difficult_challenge_2/
 */

double elapsedTime(chrono::time_point<chrono::system_clock> end, chrono::time_point<chrono::system_clock> begin){
    
     return chrono::duration_cast<chrono::seconds>(end - begin).count();
    
}

int write(string t){

    ofstream writer("noted.txt", ios::app);

    
    if (!writer) {
        cout << "Error opening file" << endl;
        // Signal that an error occurred
        return -1;
    } else {
        writer << t << endl;
    }
    writer.close();
}

int main(int argc, char** argv) {
    string input;
    string filename;
    bool running = true;

    chrono::time_point<chrono::system_clock> begin;
    chrono::time_point<chrono::system_clock> end;
    chrono::time_point<chrono::system_clock> lap;
    vector <double> laps(0);

    while (running) {
        cout << "start, stop and lap" << endl;
        cin >> input;

        if (input == "start" || input == "restart") {
            begin = chrono::system_clock::now();
            cout << "stopwatch started: " << endl;


        } else if (input == "stop") {
            end = chrono::system_clock::now();
            cout << "stopwatch stopped: " << elapsedTime(end, begin) << endl;
            
            write("end time: " + to_string(elapsedTime(end, begin)));


        } else if (input == "lap") {
            lap = chrono::system_clock::now();
            laps.push_back(elapsedTime(lap, begin));
            for (int i = 0; i < laps.size(); ++i){
               cout << laps[i] << endl;
               write("lap: " + to_string(laps[i]));
            }
            
        }
    }

    return 0;
}

