/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 792
 *
 * Created on April 22, 2018, 10:45 AM
 */

#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <map> 
#include <sstream>
#include <algorithm>

using namespace std;

/* 
 * An implementation of a text summarizer that can take a block of text 
 * (e.g. a paragraph) and emit a one or two sentence summarization of it. 
 * It uses a stopword list to filter irrelevant words.
 * One limitation: sentences must still be on seperate lines. 
 * https://www.reddit.com/r/dailyprogrammer/comments/683w4s/20170428_challenge_312_hard_text_summarizer/
 */

vector <string> wordList(0);
vector<vector <string>> sentences(0);
vector<string> sentencesU(0);
map<string, unsigned int> wordsCount;
map<int, int> score;
//two test files 'text.txt' and 'text2.txt' are included
string textURL = "text2.txt"; 
string wordlistURL = "wordlist.txt";



string toLowerCase(string input) {
    string result = input;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

string removeSpaces(string input) {
    size_t start = 0, stop = input.length() - 1;
    while (input[stop] == ' ') {
        stop--;
    }
    while (input[start] == ' ') {
        start++;
    }
    return input.substr(start, stop - start + 1);
}

string removePunctuation(string input) {
    if (all_of(input.begin(), input.end(), ::isalnum)) {
        return input;
    }
    size_t start = 0, stop = input.length() - 1;
    while (!isalnum(input[stop])) {
        stop--;
    }
    while (!isalnum(input[start])) {
        start++;
    }
    return input.substr(start, stop - start + 1);
}

int loadWords() {

    string word;
    ifstream reader(wordlistURL);

    if (!reader) {

        cout << "Error opening file" << endl;
        return -1;

    } else {

        while (getline(reader, word, ';')) {
            wordList.push_back(word);
        }

        reader.close();
        return 0;

    }
}

int loadText() {

    string paragraph;
    int counter = 1;
    ifstream reader(textURL);

    if (!reader) {

        cout << "Error opening file" << endl;
        return -1;

    } else {

        while (getline(reader, paragraph)) {
            sentences.resize(counter);

            stringstream ss;
            ss << paragraph;
            sentencesU.push_back(paragraph);

            while (ss.good()) {
                string word;
                ss >> word;

                word = toLowerCase(removeSpaces(removePunctuation(word)));
                //ignore the words that are on the wordlist
                if (!(find(wordList.begin(), wordList.end(), word) !=
                        wordList.end()) && word.length() > 1) {
                    sentences[counter - 1].push_back(word);
                    if (wordsCount.find(word) == wordsCount.end()) { 
                        wordsCount[word] = 1; 
                    } else { 
                        wordsCount[word]++;
                    }
                }
            }
            counter++;
        }
        reader.close();
        return 0;
    }
}

int summarize() {

    //initialize score map
    for (int i = 0; i < sentences.size(); i++) {
        score[i] = 0;
    }

    //take most important words
    typedef pair<string, int> Pair;
    vector<Pair> results(5);
    partial_sort_copy(
            wordsCount.begin(), wordsCount.end(),
            results.begin(), results.end(),
            [](const Pair &lhs, const Pair & rhs) {
                return lhs.second > rhs.second; }
    );

    //for each sentence, for each word, for each popular word give score to 
    //sentence based on amount of important words
    for (int i = 0; i < sentences.size(); i++) {
        for (int j = 0; j < sentences[i].size(); j++) {
            for (int k = 0; k < results.size(); k++) {
                if (results[k].first == sentences[i][j]){
                    score[i]++;
                }
            }
        }
    }

    return 0;
}

int print() {
    
    int firstSentence;
    int secondSentence;
    
    //take most important words
    typedef pair<int, int> Pair;
    vector<Pair> results(2);
    partial_sort_copy(
            score.begin(), score.end(),
            results.begin(), results.end(),
            [](const Pair &lhs, const Pair & rhs) {
                return lhs.second > rhs.second; }
    );
    
    if(results[0].first < results[1].first){
        firstSentence = results[0].first;
        secondSentence = results[1].first;
    } else{
        firstSentence = results[1].first;
        secondSentence = results[0].first;
    }
        cout << sentencesU[firstSentence] << endl;
        cout << sentencesU[secondSentence] << endl;

    return 0;
   
}

int main(int argc, char** argv) {

    loadWords();
    loadText();
    summarize();
    print();

    return 0;
}

